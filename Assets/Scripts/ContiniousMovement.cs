using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR;
using UnityEngine.XR.Interaction.Toolkit;
using Unity.XR.CoreUtils;

public class ContiniousMovement : MonoBehaviour
{
    public XRNode inputSource;
    private CharacterController character;
    public float additionalHeight = 0.2f;
    private Vector2 inputAxis;
    private XROrigin origin;
    
    public float speed = 1f;
    // Start is called before the first frame update
    void Start()
    {
        character = GetComponent<CharacterController>();
        origin = GetComponent<XROrigin>();
    }

    // Update is called once per frame
    void Update()
    {
        InputDevice device = InputDevices.GetDeviceAtXRNode(inputSource);
        device.TryGetFeatureValue(CommonUsages.primary2DAxis,out inputAxis); 
    }
    private void FixedUpdate(){
        CapsuleFollowHeadset();
        Quaternion headYaw = Quaternion.Euler(0,origin.Camera.transform.eulerAngles.y,0);
        Vector3 direction = headYaw *new Vector3(inputAxis.x,0,inputAxis.y);
        character.Move(direction*Time.fixedDeltaTime*speed);
    }
    void CapsuleFollowHeadset(){
        character.height = origin.CameraInOriginSpaceHeight + additionalHeight;
        Vector3 capsuleCenter = transform.InverseTransformPoint(origin.Camera.transform.position);
        character.center = new Vector3(capsuleCenter.x ,  character.height/2 + character.skinWidth ,capsuleCenter.y );
    }
}
