---
title: "TN065: Suporte de Interface dupla para servidores de automação OLE | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.ole
dev_langs:
- C++
helpviewer_keywords:
- dual interfaces [MFC], OLE Automation
- TN065 [MFC]
- ACDUAL sample [MFC]
- Automation servers [MFC], dual-interface support
ms.assetid: b5c8ed09-2f7f-483c-80fc-2a47ad896063
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 959938be27e66a765ee0ae9e5aef9b3c1f1aed6f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="tn065-dual-interface-support-for-ole-automation-servers"></a>TN065: suporte para interface dupla para servidores de automação OLE
> [!NOTE]
>  A Observação técnica a seguir não foi atualizada desde que ele foi incluído primeiro na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação on-line.  
  
 Esta anotação discute como adicionar suporte de interface dupla para um aplicativo de servidor com base em MFC de automação OLE. O [ACDUAL](../visual-cpp-samples.md) exemplo ilustra o suporte de interface dupla, e o código de exemplo essa observação é realizado de ACDUAL. As macros, como descritas nesta nota, `DECLARE_DUAL_ERRORINFO`, `DUAL_ERRORINFO_PART`, e `IMPLEMENT_DUAL_ERRORINFO`, fazem parte do exemplo de ACDUAL e pode ser encontrado em MFCDUAL. H.  
  
## <a name="dual-interfaces"></a>Interfaces duplas  
 Embora a automação OLE permitem que você implemente um `IDispatch` interface, uma interface VTBL ou uma interface dupla (que abrange ambos), a Microsoft recomenda que você implemente as interfaces duplas para todos os objetos de automação OLE de exposto. Interfaces duplas tem vantagens significativas sobre `IDispatch`-somente ou somente VTBL interfaces:  
  
-   Associação podem ocorrer em tempo de compilação por meio da interface VTBL ou em tempo de execução por meio de `IDispatch`.  
  
-   Controladores de automação OLE que podem usar a interface VTBL podem se beneficiar de melhor desempenho.  
  
-   Controladores de automação OLE existentes que usam o `IDispatch` interface continuarão a funcionar.  
  
-   A interface VTBL é mais fácil de chamada de C++.  
  
-   Interfaces duplas são necessárias para compatibilidade com recursos de suporte de objeto do Visual Basic.  
  
## <a name="adding-dual-interface-support-to-a-ccmdtarget-based-class"></a>Adicionando suporte a Interface dupla a uma classe com base em CCmdTarget  
 Uma interface dupla é apenas uma interface personalizada derivada de `IDispatch`. A maneira mais simples de implementar suporte de interface dupla em um `CCmdTarget`-baseado em classe é implementam primeiro a distribuição normal de interface em sua classe usando MFC e ClassWizard, em seguida, adicionar a interface personalizada mais tarde. A maior parte do tempo, sua implementação de interface personalizada simplesmente delegará para o MFC `IDispatch` implementação.  
  
 Primeiro, modifique o arquivo ODL do seu servidor para definir as interfaces duplas de seus objetos. Para definir uma interface dupla, você deve usar uma declaração de interface, em vez do `DISPINTERFACE` instrução que geram os assistentes do Visual C++. Em vez de remover existente `DISPINTERFACE` instrução, adicionar uma nova declaração de interface. Mantendo o `DISPINTERFACE` formulário, que você pode continuar a usar ClassWizard para adicionar propriedades e métodos para o objeto, mas você deve adicionar os equivalentes de propriedades e métodos para sua declaração de interface.  
  
 Uma declaração de interface para uma interface dupla deve ter o **OLEAUTOMATION** e **DUAL** atributos e a interface devem ser derivado de `IDispatch`. Você pode usar o [GUIDGEN](../visual-cpp-samples.md) amostra para criar um **IID** para a interface dupla:  
  
```  
[ uuid(0BDD0E81-0DD7-11cf-BBA8-444553540000), // IID_IDualAClick  
    oleautomation, 
    dual 
]  
interface IDualAClick : IDispatch  
 {  
 };  
```  
  
 Uma vez que a declaração de interface em vigor, começar a adicionar entradas para os métodos e propriedades. Interfaces duplas, você precisa reorganizar as listas de parâmetros para que seus métodos e as funções do acessador de propriedade na interface dupla retornam um `HRESULT` e passar valores de retorno como parâmetros com os atributos `[retval,out]`. Lembre-se de que para as propriedades, você precisará adicionar uma leitura (`propget`) e gravar (`propput`) acesso de função com a mesma id. Por exemplo:  
  
```  
[propput,
    id(1)] HRESULT text([in] BSTR newText);

[propget,
    id(1)] HRESULT text([out,
    retval] BSTR* retval);
```  
  
 Depois que seus métodos e propriedades são definidas, você precisa adicionar uma referência para a declaração de interface na instrução coclass. Por exemplo:  
  
```  
[ uuid(4B115281-32F0-11cf-AC85-444553540000) ]  
coclass Document  
{  
    dispinterface IAClick;  
 [default] interface IDualAClick;  
};  
```  
  
 Depois que o arquivo ODL tiver sido atualizado, use o mecanismo de mapa de interface do MFC para definir uma classe de implementação para a interface dupla em sua classe de objeto e verifique as entradas correspondentes no MFC `QueryInterface` mecanismo. Você precisa de uma entrada no `INTERFACE_PART` bloco para cada entrada na declaração de interface do ODL mais as entradas para uma interface de expedição. Cada entrada ODL com o **propput** atributo precisa de uma função chamada `put_propertyname`. Cada entrada com o **propget** atributo precisa de uma função chamada `get_propertyname`.  
  
 Para definir uma classe de implementação para a sua interface dupla, adicione um `DUAL_INTERFACE_PART` bloco à sua definição de classe do objeto. Por exemplo:  
  
```  
BEGIN_DUAL_INTERFACE_PART(DualAClick,
    IDualAClick)  
    STDMETHOD(put_text)(THIS_ BSTR newText);

    STDMETHOD(get_text)(THIS_ BSTR FAR* retval);

    STDMETHOD(put_x)(THIS_ short newX);

    STDMETHOD(get_x)(THIS_ short FAR* retval);

    STDMETHOD(put_y)(THIS_ short newY);

    STDMETHOD(get_y)(THIS_ short FAR* retval);

    STDMETHOD(put_Position)(THIS_ IDualAutoClickPoint FAR* newPosition);

    STDMETHOD(get_Position)(THIS_ IDualAutoClickPoint FAR* FAR* retval);

    STDMETHOD(RefreshWindow)(THIS);

 STDMETHOD(SetAllProps)(THIS_ short x,
    short y,
    BSTR text);

    STDMETHOD(ShowWindow)(THIS);

END_DUAL_INTERFACE_PART(DualAClick) 
```  
  
 Para conectar-se a interface dupla do MFC [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms687230) mecanismo, adicione um `INTERFACE_PART` entrada para mapa de interface:  
  
```  
BEGIN_INTERFACE_MAP(CAutoClickDoc,
    CDocument)  
    INTERFACE_PART(CAutoClickDoc,
    DIID_IAClick,
    Dispatch)  
    INTERFACE_PART(CAutoClickDoc,
    IID_IDualAClick,
    DualAClick)  
END_INTERFACE_MAP()  
```  
  
 Em seguida, você precisa preencher a implementação da interface. A maior parte do tempo, você poderá delegar a MFC existente `IDispatch` implementação. Por exemplo:  
  
```  
STDMETHODIMP_(ULONG) CAutoClickDoc::XDualAClick::AddRef()  
{  
    METHOD_PROLOGUE(CAutoClickDoc,
    DualAClick)  
    return pThis->ExternalAddRef();

}  
STDMETHODIMP_(ULONG) CAutoClickDoc::XDualAClick::Release()  
{  
    METHOD_PROLOGUE(CAutoClickDoc,
    DualAClick)  
    return pThis->ExternalRelease();

}  
STDMETHODIMP CAutoClickDoc::XDualAClick::QueryInterface(
    REFIID iid,
    LPVOID* ppvObj)  
{  
    METHOD_PROLOGUE(CAutoClickDoc,
    DualAClick)  
    return pThis->ExternalQueryInterface(&iid,
    ppvObj);

}  
STDMETHODIMP CAutoClickDoc::XDualAClick::GetTypeInfoCount(
    UINT FAR* pctinfo)  
{  
    METHOD_PROLOGUE(CAutoClickDoc,
    DualAClick)  
    LPDISPATCH lpDispatch = pThis->GetIDispatch(FALSE);

    ASSERT(lpDispatch != NULL);

    return lpDispatch->GetTypeInfoCount(pctinfo);

}  
STDMETHODIMP CAutoClickDoc::XDualAClick::GetTypeInfo(
    UINT itinfo,
    LCID lcid,
    ITypeInfo FAR* FAR* pptinfo)  
{  
    METHOD_PROLOGUE(CAutoClickDoc,
    DualAClick)  
    LPDISPATCH lpDispatch = pThis->GetIDispatch(FALSE);

    ASSERT(lpDispatch != NULL);

    return lpDispatch->GetTypeInfo(itinfo,
    lcid,
    pptinfo);

}  
STDMETHODIMP CAutoClickDoc::XDualAClick::GetIDsOfNames(
    REFIID riid,
    OLECHAR FAR* FAR* rgszNames,
    UINT cNames,  
    LCID lcid,
    DISPID FAR* rgdispid)   
{  
    METHOD_PROLOGUE(CAutoClickDoc,
    DualAClick)  
    LPDISPATCH lpDispatch = pThis->GetIDispatch(FALSE);

    ASSERT(lpDispatch != NULL);

    return lpDispatch->GetIDsOfNames(riid,
    rgszNames,
    cNames,   
    lcid,
    rgdispid);

}  
STDMETHODIMP CAutoClickDoc::XDualAClick::Invoke(
    DISPID dispidMember,
    REFIID riid,
    LCID lcid,
    WORD wFlags,  
    DISPPARAMS FAR* pdispparams,
    VARIANT FAR* pvarResult,  
    EXCEPINFO FAR* pexcepinfo,
    UINT FAR* puArgErr)  
{  
    METHOD_PROLOGUE(CAutoClickDoc,
    DualAClick)  
    LPDISPATCH lpDispatch = pThis->GetIDispatch(FALSE);

    ASSERT(lpDispatch != NULL);

    return lpDispatch->Invoke(dispidMember,
    riid,
    lcid,  
    wFlags,
    pdispparams,
    pvarResult,  
    pexcepinfo,
    puArgErr);

}  
```  
  
 Para funções do acessador de propriedade e métodos do objeto, você precisa preencher a implementação. As funções de método e propriedade geralmente podem delegar para os métodos gerados usando ClassWizard. No entanto, se você definir as propriedades para acessar variáveis diretamente, você precisa escrever o código para o valor de get/put para a variável. Por exemplo:  
  
```  
STDMETHODIMP CAutoClickDoc::XDualAClick::put_text(BSTR newText)  
{  
    METHOD_PROLOGUE(CAutoClickDoc,
    DualAClick) *// MFC automatically converts from Unicode BSTR to *// Ansi CString,
    if necessary...  
    pThis->m_str = newText;  
    return NOERROR;  
}  
STDMETHODIMP CAutoClickDoc::XDualAClick::get_text(BSTR* retval)  
{  
    METHOD_PROLOGUE(CAutoClickDoc,
    DualAClick) *// MFC automatically converts from Ansi CString to *// Unicode BSTR,
    if necessary...  
    pThis->m_str.SetSysString(retval);

 return NOERROR;  
}  
```  
  
## <a name="passing-dual-interface-pointers"></a>Ponteiros de Interface dupla de passagem  
 Passar o ponteiro de interface dupla não é simples, especialmente se você precisar chamar `CCmdTarget::FromIDispatch`. `FromIDispatch`funciona apenas em MFC `IDispatch` ponteiros. Uma maneira de resolver esse problema é a consulta para o original `IDispatch` ponteiro conjunto backup pelo MFC e passar esse ponteiro para funções que precisam dela. Por exemplo:  
  
```  
STDMETHODIMP CAutoClickDoc::XDualAClick::put_Position(
    IDualAutoClickPoint FAR* newPosition)  
{  
    METHOD_PROLOGUE(CAutoClickDoc,
    DualAClick)  
    LPDISPATCH lpDisp = NULL;  
    newPosition->QueryInterface(IID_IDispatch, (LPVOID*)&lpDisp);

    pThis->SetPosition(lpDisp);

 lpDisp->Release();
return NOERROR;  
}  
```  
  
 Antes de passar um ponteiro de volta por meio do método de interface dupla, talvez seja necessário convertê-lo de MFC `IDispatch` ponteiro para o ponteiro de interface dupla. Por exemplo:  
  
```  
STDMETHODIMP CAutoClickDoc::XDualAClick::get_Position(
    IDualAutoClickPoint FAR* FAR* retval)  
{  
    METHOD_PROLOGUE(CAutoClickDoc,
    DualAClick)  
    LPDISPATCH lpDisp;  
    lpDisp = pThis->GetPosition();
lpDisp->QueryInterface(IID_IDualAutoClickPoint, (LPVOID*)retval);

    return NOERROR;  
}  
```  
  
## <a name="registering-the-applications-type-library"></a>Ao registrar a biblioteca de tipo do aplicativo  
 AppWizard não gera código para registrar a biblioteca de tipos de um aplicativo servidor de automação OLE com o sistema. Existem outras maneiras de registrar a biblioteca de tipos, é conveniente para que o aplicativo registrar a biblioteca de tipos, quando está atualizando as informações de tipo OLE, ou seja, sempre que o aplicativo for executado autônomo.  
  
 Para registrar a biblioteca de tipos aplicativo sempre que o aplicativo for executado autônomo:  
  
-   Inclua AFXCTL. H em seu padrão inclui o arquivo de cabeçalho STDAFX. H, para acessar a definição de `AfxOleRegisterTypeLib` função.  
  
-   Em seu aplicativo `InitInstance` funcionar, localize a chamada para `COleObjectFactory::UpdateRegistryAll`. Seguindo essa chamada, adicione uma chamada para `AfxOleRegisterTypeLib`, especificando o **LIBID** correspondente à sua biblioteca de tipos, juntamente com o nome da sua biblioteca de tipo:  
  
 ' ' * / / Quando um aplicativo de servidor é iniciado autônomo, é uma boa ideia * / / para atualizar o registro do sistema, caso ele tenha sido danificado.  
    m_server. UpdateRegistry(OAT_DISPATCH_OBJECT);

 COleObjectFactory::UpdateRegistryAll(); * / / DUAL_SUPPORT_START * / / certificar-se de que a biblioteca de tipos foi registrada ou interface dupla não funcionará.  
AfxOleRegisterTypeLib(AfxGetInstanceHandle(), LIBID_ACDual, _T("AutoClik.TLB")); * / / DUAL_SUPPORT_END  
 ```  
  
## Modifying Project Build Settings to Accommodate Type Library Changes  
 To modify a project's build settings so that a header file containing **UUID** definitions is generated by MkTypLib whenever the type library is rebuilt:  
  
1.  On the **Build** menu, click **Settings**, and then select the ODL file from the file list for each configuration.  
  
2.  Click the **OLE Types** tab and specify a filename in the **Output header** filename field. Use a filename that is not already used by your project, because MkTypLib will overwrite any existing file. Click **OK** to close the **Build Settings** dialog box.  
  
 To add the **UUID** definitions from the MkTypLib-generated header file to your project:  
  
1.  Include the MkTypLib-generated header file in your standard includes header file, STDAFX.H.  
  
2.  Create a new file, INITIIDS.CPP, and add it to your project. In this file, include your MkTypLib-generated header file after including OLE2.H and INITGUID.H:  
  
 ```  
    initIIDs.c: define IIDs para interfaces duplas  
    Isso não deve ser criado com cabeçalho pré-compilado.  
      #<a name="include-ole2h"></a>incluir < ole2.h >  
      #<a name="include-initguidh"></a>inclua < initguid >.  
      #<a name="include-acdualh"></a>incluir "acdual.h"  
 ```  
  
3.  On the **Build** menu, click **Settings**, and then select INITIIDS.CPP from the file list for each configuration.  
  
4.  Click the **C++** tab, click category **Precompiled Headers**, and select the **Not using precompiled headers** radio button. Click OK to close the **Build Settings** dialog box.  
  
## Specifying the Correct Object Class Name in the Type Library  
 The wizards shipped with Visual C++ incorrectly use the implementation class name to specify the coclass in the server's ODL file for OLE-creatable classes. While this will work, the implementation class name is probably not the class name you want users of your object to use. To specify the correct name, open the ODL file, locate each coclass statement, and replace the implementation class name with the correct external name.  
  
 Note that when the coclass statement is changed, the variable names of **CLSID**s in the MkTypLib-generated header file will change accordingly. You will need to update your code to use the new variable names.  
  
## Handling Exceptions and the Automation Error Interfaces  
 Your automation object's methods and property accessor functions may throw exceptions. If so, you should handle them in your dual-interface implementation and pass information about the exception back to the controller through the OLE Automation error-handling interface, **IErrorInfo**. This interface provides for detailed, contextual error information through both `IDispatch` and VTBL interfaces. To indicate that an error handler is available, you should implement the **ISupportErrorInfo** interface.  
  
 To illustrate the error-handling mechanism, assume that the ClassWizard-generated functions used to implement the standard dispatch support throw exceptions. MFC's implementation of **IDispatch::Invoke** typically catches these exceptions and converts them into an EXCEPTINFO structure that is returned through the `Invoke` call. However, when VTBL interface is used, you are responsible for catching the exceptions yourself. As an example of protecting your dual-interface methods:  
  
```  
STDMETHODIMP CAutoClickDoc::XDualAClick::put_text(BSTR newText)  
{  
    METHOD_PROLOGUE (CAutoClickDoc, DualAClick)  
    TRY_DUAL(IID_IDualAClick) {* / / MFC converte automaticamente de Unicode BSTR para * / / CString Ansi, se necessário...  
    pEsse -> m_str = TextoNovo;  
    Retorna NOERROR;  
 }  
    CATCH_ALL_DUAL}  
```  
  
 `CATCH_ALL_DUAL` takes care of returning the correct error code when an exception occurs. `CATCH_ALL_DUAL` converts an MFC exception into OLE Automation error-handling information using the **ICreateErrorInfo** interface. (An example `CATCH_ALL_DUAL` macro is in the file MFCDUAL.H in the [ACDUAL](../visual-cpp-samples.md) sample. The function it calls to handle exceptions, `DualHandleException`, is in the file MFCDUAL.CPP.) `CATCH_ALL_DUAL` determines the error code to return based on the type of exception that occurred:  
  
- [COleDispatchException](../mfc/reference/coledispatchexception-class.md) - In this case, `HRESULT` is constructed using the following code:  
  
 ```  
    hr = MAKE_HRESULT(SEVERITY_ERROR,
    FACILITY_ITF,   
 (e -> m_wCode + 0x200));

 ```  
  
     This creates an `HRESULT` specific to the interface that caused the exception. The error code is offset by 0x200 to avoid any conflicts with system-defined `HRESULT`s for standard OLE interfaces.  
  
- [CMemoryException](../mfc/reference/cmemoryexception-class.md) - In this case, `E_OUTOFMEMORY` is returned.  
  
-   Any other exception - In this case, `E_UNEXPECTED` is returned.  
  
 To indicate that the OLE Automation error handler is used, you should also implement the **ISupportErrorInfo** interface.  
  
 First, add code to your automation class definition to show it supports **ISupportErrorInfo**.  
  
 Second, add code to your automation class's interface map to associate the **ISupportErrorInfo** implementation class with MFC's `QueryInterface` mechanism. The `INTERFACE_PART` statement matches the class defined for **ISupportErrorInfo**.  
  
 Finally, implement the class defined to support **ISupportErrorInfo**.  
  
 (The [ACDUAL](../visual-cpp-samples.md) sample contains three macros to help do these three steps, `DECLARE_DUAL_ERRORINFO`, `DUAL_ERRORINFO_PART`, and `IMPLEMENT_DUAL_ERRORINFO`, all contained in MFCDUAL.H.)  
  
 The following example implements a class defined to support **ISupportErrorInfo**. `CAutoClickDoc` is the name of your automation class and `IID_IDualAClick` is the **IID** for the interface that is the source of errors reported through the OLE Automation error object:  
  
```  
STDMETHODIMP_(ULong) CAutoClickDoc::XSupportErrorInfo::AddRef()   
{  
    METHOD_PROLOGUE (CAutoClickDoc, SupportErrorInfo)   
    retorno pEsse -> ExternalAddRef();

}   
STDMETHODIMP_(ULong) CAutoClickDoc::XSupportErrorInfo::Release()   
{   
    METHOD_PROLOGUE (CAutoClickDoc, SupportErrorInfo)   
    retorno pEsse -> ExternalRelease();

}   
STDMETHODIMP CAutoClickDoc::XSupportErrorInfo::QueryInterface (iid REFIID, LPVOID * ppvObj)   
{   
    METHOD_PROLOGUE (CAutoClickDoc, SupportErrorInfo)   
    retorno pEsse -> ExternalQueryInterface (& iid, ppvObj);

}   
STDMETHODIMP CAutoClickDoc::XSupportErrorInfo::InterfaceSupportsErrorInfo REFIID iid)   
{   
    METHOD_PROLOGUE (CAutoClickDoc, SupportErrorInfo)   
    retornar (iid = = IID_IDualAClick) S_OK: S_FALSE;   
}  
```  
  
## See Also  
 [Technical Notes by Number](../mfc/technical-notes-by-number.md)   
 [Technical Notes by Category](../mfc/technical-notes-by-category.md)

