using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.Interaction.Toolkit;
public class SprayHeadgun : MonoBehaviour
{   
    public GameObject SprayParticle;
    public XRGrabInteractable controllerXRGrab;
   [SerializeField] private GameObject _bulletHolePrefab ;
    // Start is called before the first frame update
    //private InputDevice targetDevice;
    public InputHelpers.Button drillButton;
    public XRController rightHand;
    public float SpawnRate = 1F;
     private float timestamp = 0F;
    public float range = 100f;    
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
       if( controllerXRGrab.isSelected){
        if (InputHelpers.IsPressed(rightHand.inputDevice , drillButton, out bool isActivated)&& isActivated && Time.time > timestamp){
            timestamp = Time.time + SpawnRate;
            Shoot();
        }
        if (InputHelpers.IsPressed(rightHand.inputDevice , drillButton, out bool isActivate)&& isActivate){
            SprayParticle.SetActive(true);
        }
        else{
            SprayParticle.SetActive(false);
        }
       }
        
    }
    void Shoot(){
        RaycastHit hit;
        if(Physics.Raycast(transform.position, transform.TransformDirection(Vector3.forward) , out hit , range)){
            GameObject obj = Instantiate(_bulletHolePrefab, hit.point , Quaternion.LookRotation(hit.normal));
            obj.transform.position += obj.transform.forward / 1000;
        }
    }
}
