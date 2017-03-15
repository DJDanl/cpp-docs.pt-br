---
title: "TN065: suporte para interface dupla para servidores de automa&#231;&#227;o OLE | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.ole"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Exemplo de ACDUAL [MFC]"
  - "Servidores de automação, suporte a interface dupla"
  - "interfaces duplas, Automação OLE"
  - "TN065"
ms.assetid: b5c8ed09-2f7f-483c-80fc-2a47ad896063
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN065: suporte para interface dupla para servidores de automa&#231;&#227;o OLE
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que ela foi incluída pela primeira vez na documentação online.  Como resultado, alguns procedimentos e tópicos podem estar incorretos ou expirados.  Para obter as informações mais recentes, é recomendável que você procure o tópico de interesse no índice de documentação online.  
  
 Essa observação discute como adicionar o suporte à interface dual e a um aplicativo de servidor baseado MFC\- de Automação OLE.  O exemplo de [ACDUAL](../top/visual-cpp-samples.md) ilustra o suporte à interface dual e, e o código de exemplo nesta observação é obtido de ACDUAL.  Macros descritos nesta observe que, como `DECLARE_DUAL_ERRORINFO`, `DUAL_ERRORINFO_PART`, e `IMPLEMENT_DUAL_ERRORINFO`, fazem parte do exemplo de ACDUAL e podem ser localizados em. MFCDUAL.H.  
  
## Interfaces duplas  
 Embora a Automação OLE permite que você implementa uma interface de `IDispatch` , uma interface de VTBL, ou uma interface dupla \(que inclui ambos\), a Microsoft recomenda fortemente que você implementa as interfaces duplas para todos os objetos expõe de Automação OLE.  As interfaces duplas têm vantagens significativas sobre `IDispatch`apenas ou interfaces de VTBL\-only:  
  
-   A associação pode ocorrer em tempo de compilação por meio da interface de VTBL, ou em tempo de execução com `IDispatch`.  
  
-   Os controladores de Automação OLE que podem usar a interface de VTBL podem se beneficiar de desempenho aprimorado.  
  
-   Controladores existentes de Automação OLE que usam a interface de `IDispatch` continuarão funcionando.  
  
-   A interface de VTBL é mais fácil de chamar C\+\+.  
  
-   As interfaces duplas são necessárias para compatibilidade com os recursos de suporte do objeto do Visual Basic.  
  
## Adicionando suporte à interface dual e uma classe com base CCmdTarget\-  
 Uma interface dupla é realmente só uma interface personalizado derivada de `IDispatch`.  A maneira mais simples de implementar o suporte à interface dual e em uma classe baseada no SSIS `CCmdTarget`é primeiro implementa a interface comum de distribuição em sua classe que usa o MFC e o ClassWizard, adiciona a interface personalizado posterior.  Em geral, sua implementação da interface delegará somente de volta para a implementação de MFC `IDispatch` .  
  
 Primeiro, modifique o arquivo de ODL para que seu servidor definir interfaces duplas para seus objetos.  Para definir uma interface dupla, você deve usar uma instrução da interface, em vez da instrução de `DISPINTERFACE` que os assistentes do Visual C\+\+ gerenciem.  Em vez de remover a instrução existente de `DISPINTERFACE` , adicione uma nova instrução da interface.  Mantendo o formulário de `DISPINTERFACE` , você pode continuar a usar ClassWizard para adicionar propriedades e métodos para seu objeto, mas você deve adicionar as propriedades e os métodos equivalentes à instrução da interface.  
  
 Uma instrução da interface para uma interface dupla deve ter os atributos de **OLEAUTOMATION** e de **DUAL** , e a interface deve ser derivada de `IDispatch`.  Você pode usar a amostra de [GUIDGEN](../top/visual-cpp-samples.md) para criar **IID** para a interface dupla:  
  
```  
[ uuid(0BDD0E81-0DD7-11cf-BBA8-444553540000), // IID_IDualAClick  
   oleautomation,  
   dual  
]  
interface IDualAClick : IDispatch  
  {  
  };  
```  
  
 Quando você tem a instrução da interface no lugar, inicie adicionar entradas para os métodos e as propriedades.  Para interfaces duplas, você precisa reordenar as listas de parâmetros de modo que os métodos e funções do acessador da propriedade na interface dupla retornem `HRESULT` e passou seus valores de retorno como parâmetros com os atributos `[retval,out]`.  Lembre\-se de que para propriedades, você precisará adicionar uma leitura \(`propget`\) e a função de acesso de gravação \(`propput`\) com a mesma ID  Por exemplo:  
  
```  
[propput, id(1)] HRESULT text([in] BSTR newText);  
[propget, id(1)] HRESULT text([out, retval] BSTR* retval);  
```  
  
 Depois de seus métodos e propriedades são definidas, você precisa adicionar uma referência à instrução da interface na instrução de coclass.  Por exemplo:  
  
```  
[ uuid(4B115281-32F0-11cf-AC85-444553540000) ]  
coclass Document  
{  
   dispinterface IAClick;  
   [default] interface IDualAClick;  
};  
```  
  
 Uma vez que o arquivo de ODL foi atualizado, use o mecanismo da interface de MFC para definir uma classe de implementação da interface dupla em sua classe de objeto e fazer as entradas correspondentes no mecanismo de `QueryInterface` MFC.  Você precisa de uma entrada no bloco de `INTERFACE_PART` para cada entrada na instrução da interface de ODL, mais as entradas para uma interface de distribuição.  Cada entrada de ODL com o atributo de **propput** precisa de uma função chamada `put_propertyname`.  Cada entrada com o atributo de **propget** precisa de uma função chamada `get_propertyname`.  
  
 Para definir uma classe de implementação da interface dupla, adicione um bloco de `DUAL_INTERFACE_PART` a sua definição de classe do objeto.  Por exemplo:  
  
```  
BEGIN_DUAL_INTERFACE_PART(DualAClick, IDualAClick)  
  STDMETHOD(put_text)(THIS_ BSTR newText);  
  STDMETHOD(get_text)(THIS_ BSTR FAR* retval);  
  STDMETHOD(put_x)(THIS_ short newX);  
  STDMETHOD(get_x)(THIS_ short FAR* retval);  
  STDMETHOD(put_y)(THIS_ short newY);  
  STDMETHOD(get_y)(THIS_ short FAR* retval);  
  STDMETHOD(put_Position)(THIS_ IDualAutoClickPoint FAR* newPosition);  
  STDMETHOD(get_Position)(THIS_ IDualAutoClickPoint FAR* FAR* retval);  
  STDMETHOD(RefreshWindow)(THIS);  
  STDMETHOD(SetAllProps)(THIS_ short x, short y, BSTR text);  
  STDMETHOD(ShowWindow)(THIS);  
END_DUAL_INTERFACE_PART(DualAClick)  
```  
  
 Para se conectar a interface dupla para o mecanismo de [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms687230) MFC, adicione uma entrada de `INTERFACE_PART` no mapa da interface:  
  
```  
BEGIN_INTERFACE_MAP(CAutoClickDoc, CDocument)  
  INTERFACE_PART(CAutoClickDoc, DIID_IAClick, Dispatch)  
  INTERFACE_PART(CAutoClickDoc, IID_IDualAClick, DualAClick)  
END_INTERFACE_MAP()  
```  
  
 Em seguida, você precisará preencher a implementação da interface.  Em geral, você poderá delegar à implementação existente MFC `IDispatch` .  Por exemplo:  
  
```  
STDMETHODIMP_(ULONG) CAutoClickDoc::XDualAClick::AddRef()  
{  
   METHOD_PROLOGUE(CAutoClickDoc, DualAClick)  
   return pThis->ExternalAddRef();  
}  
STDMETHODIMP_(ULONG) CAutoClickDoc::XDualAClick::Release()  
{  
   METHOD_PROLOGUE(CAutoClickDoc, DualAClick)  
   return pThis->ExternalRelease();  
}  
STDMETHODIMP CAutoClickDoc::XDualAClick::QueryInterface(  
             REFIID iid, LPVOID* ppvObj)  
{  
   METHOD_PROLOGUE(CAutoClickDoc, DualAClick)  
   return pThis->ExternalQueryInterface(&iid, ppvObj);  
}  
STDMETHODIMP CAutoClickDoc::XDualAClick::GetTypeInfoCount(  
            UINT FAR* pctinfo)  
{  
   METHOD_PROLOGUE(CAutoClickDoc, DualAClick)  
   LPDISPATCH lpDispatch = pThis->GetIDispatch(FALSE);  
   ASSERT(lpDispatch != NULL);  
   return lpDispatch->GetTypeInfoCount(pctinfo);  
}  
STDMETHODIMP CAutoClickDoc::XDualAClick::GetTypeInfo(  
          UINT itinfo, LCID lcid, ITypeInfo FAR* FAR* pptinfo)  
{  
   METHOD_PROLOGUE(CAutoClickDoc, DualAClick)  
   LPDISPATCH lpDispatch = pThis->GetIDispatch(FALSE);  
   ASSERT(lpDispatch != NULL);  
   return lpDispatch->GetTypeInfo(itinfo, lcid, pptinfo);  
}  
STDMETHODIMP CAutoClickDoc::XDualAClick::GetIDsOfNames(  
       REFIID riid, OLECHAR FAR* FAR* rgszNames, UINT cNames,  
       LCID lcid, DISPID FAR* rgdispid)   
{  
   METHOD_PROLOGUE(CAutoClickDoc, DualAClick)  
   LPDISPATCH lpDispatch = pThis->GetIDispatch(FALSE);  
   ASSERT(lpDispatch != NULL);  
   return lpDispatch->GetIDsOfNames(riid, rgszNames, cNames,   
                                    lcid, rgdispid);  
}  
STDMETHODIMP CAutoClickDoc::XDualAClick::Invoke(  
    DISPID dispidMember, REFIID riid, LCID lcid, WORD wFlags,  
    DISPPARAMS FAR* pdispparams, VARIANT FAR* pvarResult,  
    EXCEPINFO FAR* pexcepinfo, UINT FAR* puArgErr)  
{  
   METHOD_PROLOGUE(CAutoClickDoc, DualAClick)  
   LPDISPATCH lpDispatch = pThis->GetIDispatch(FALSE);  
   ASSERT(lpDispatch != NULL);  
   return lpDispatch->Invoke(dispidMember, riid, lcid,  
                             wFlags, pdispparams, pvarResult,  
                             pexcepinfo, puArgErr);  
}  
```  
  
 Para os métodos do seu objeto e as funções do acessador de propriedade, precisará preencher a implementação.  As funções do método e de propriedade podem geralmente delegar de volta para os métodos gerados usando ClassWizard.  No entanto, se você configurar propriedades para acessar diretamente variáveis, você precisa escrever o código para obter\/põe o valor na variável.  Por exemplo:  
  
```  
STDMETHODIMP CAutoClickDoc::XDualAClick::put_text(BSTR newText)  
{  
   METHOD_PROLOGUE(CAutoClickDoc, DualAClick)  
   // MFC automatically converts from Unicode BSTR to   
   // Ansi CString, if necessary...  
   pThis->m_str = newText;  
   return NOERROR;  
}  
STDMETHODIMP CAutoClickDoc::XDualAClick::get_text(BSTR* retval)  
{  
   METHOD_PROLOGUE(CAutoClickDoc, DualAClick)  
   // MFC automatically converts from Ansi CString to   
   // Unicode BSTR, if necessary...  
   pThis->m_str.SetSysString(retval);  
   return NOERROR;  
}  
```  
  
## Passando dual e ponteiros de interface  
 Passar o ponteiro de interface dual e não é simples, especialmente se você precisar chamar `CCmdTarget::FromIDispatch`.  trabalho de`FromIDispatch` apenas em ponteiros de `IDispatch` MFC.  Uma maneira de solucionar essa é consultar a configuração original do ponteiro de `IDispatch` por MFC e passar o ponteiro a funções que o precisa.  Por exemplo:  
  
```  
STDMETHODIMP CAutoClickDoc::XDualAClick::put_Position(  
      IDualAutoClickPoint FAR* newPosition)  
{  
   METHOD_PROLOGUE(CAutoClickDoc, DualAClick)  
   LPDISPATCH lpDisp = NULL;  
   newPosition->QueryInterface(IID_IDispatch, (LPVOID*)&lpDisp);  
   pThis->SetPosition(lpDisp);  
   lpDisp->Release();  
   return NOERROR;  
}  
```  
  
 Antes de transmitir um backup do ponteiro com o método da interface dual e, talvez seja necessário convertê\-los do ponteiro de MFC `IDispatch` ao ponteiro de interface dual e.  Por exemplo:  
  
```  
STDMETHODIMP CAutoClickDoc::XDualAClick::get_Position(  
      IDualAutoClickPoint FAR* FAR* retval)  
{  
   METHOD_PROLOGUE(CAutoClickDoc, DualAClick)  
   LPDISPATCH lpDisp;  
   lpDisp = pThis->GetPosition();  
   lpDisp->QueryInterface(IID_IDualAutoClickPoint, (LPVOID*)retval);  
   return NOERROR;  
}  
```  
  
## Registrando a biblioteca de tipos de aplicativo  
 AppWizard não gerencia o código para registrar uma biblioteca do tipo de aplicativo de servidor de Automação OLE no sistema.  Quando há outras maneiras de registrar a biblioteca de tipos, é conveniente ter o registro do aplicativo a biblioteca de tipos quando estiver atualizando suas informações de tipo OLE, ou seja, sempre que o aplicativo autônomo é executado.  
  
 Para registrar a biblioteca de tipos de aplicativo sempre que o aplicativo é executado apenas suporte:  
  
-   Inclua AFXCTL.H em seu padrão inclui o arquivo de cabeçalho, STDAFX.H, para acessar a definição da função de `AfxOleRegisterTypeLib` .  
  
-   Na função de `InitInstance` do seu aplicativo, localize a chamada a `COleObjectFactory::UpdateRegistryAll`.  Depois dessa chamada, adicione uma chamada a `AfxOleRegisterTypeLib`, especificando **LIBID** que corresponde à sua biblioteca de tipos, junto com o nome da biblioteca de tipos:  
  
    ```  
    // When a server application is launched stand-alone, it is a good idea  
    // to update the system registry in case it has been damaged.  
    m_server.UpdateRegistry(OAT_DISPATCH_OBJECT);  
    COleObjectFactory::UpdateRegistryAll();  
    // DUAL_SUPPORT_START  
    // Make sure the type library is registered or dual interface won't work.  
    AfxOleRegisterTypeLib(AfxGetInstanceHandle(), LIBID_ACDual, _T("AutoClik.TLB"));  
    // DUAL_SUPPORT_END  
    ```  
  
## Como modificar a construção do projeto as configurações para acomodar a biblioteca de tipos alterações  
 Para alterar configurações de criação de um projeto de modo que um arquivo de cabeçalho que contém definições de **UUID** é gerado por MkTypLib sempre que a biblioteca de tipos é recriada:  
  
1.  No menu de **Compilar** , clique em **Configurações**, e selecione o arquivo de ODL da lista de arquivos para cada configuração.  
  
2.  Clique na guia de **OLE Types** e especificar um nome de arquivo no campo de nome de arquivo de **Output header** .  Use um nome de arquivo que não é mais usado por seu projeto, pois MkTypLib substituirá qualquer arquivo existente.  **OK** Clique em para fechar a caixa de diálogo de **Configurações da Compilação** .  
  
 Para adicionar as definições de **UUID** do arquivo de cabeçalho MkTypLib\- gerado ao seu projeto:  
  
1.  Inclua o arquivo de cabeçalho MkTypLib\-gerado em seu padrão inclui o arquivo de cabeçalho, STDAFX.H.  
  
2.  Crie um novo arquivo, INITIIDS.CPP, e o adiciona ao seu projeto.  Nesse arquivo, inclua o arquivo de cabeçalho MkTypLib\- gerado depois de incluir OLE2.H e INITGUID.H:  
  
    ```  
    // initIIDs.c: defines IIDs for dual interfaces  
    // This must not be built with precompiled header.  
      #include <ole2.h>  
      #include <initguid.h>  
      #include "acdual.h"  
    ```  
  
3.  No menu de **Compilar** , clique em **Configurações**, e selecione INITIIDS.CPP da lista de arquivos para cada configuração.  
  
4.  Clique na guia de **C\+\+** , clique em categoria **Cabeçalhos Pré\-Compilados**, e selecione o botão de opção de **Não Usar Cabeçalhos Pré\-Compilados** .  Clique em OK para fechar a caixa de diálogo de **Configurações da Compilação** .  
  
## Especificando o nome da classe do objeto correto na biblioteca de tipos  
 Os assistentes fornecidos com o Visual C\+\+ usam incorretamente o nome da classe de implementação para especificar os coclass no arquivo de ODL de servidor para classes de OLE \- creatable.  Quando isso funcionará, o nome da classe de implementação não é provavelmente o nome da classe que você deseja que os usuários de seu objeto a ser usado.  Para especificar o nome correto, abra o arquivo de ODL, localize cada instrução de coclass, e substituir o nome da classe de implementação com o nome externo correto.  
  
 Observe que quando a instrução de coclass é alterada, os nomes de variável de **CLSID**s no arquivo de cabeçalho MkTypLib\- gerado serão alterados de acordo.  Você precisará atualizar seu código para usar os novos nomes de variável.  
  
## Manipulando exceções e as interfaces de erro de automação  
 Os métodos do objeto de automação e funções do acessador de propriedade podem lançar exceções.  Nesse caso, você deve tratá\-las em sua implementação da interface e dual e transmitir informações sobre a exceção de volta ao controlador por meio da interface de tratamento de erro de Automação OLE, **IErrorInfo**.  Essa interface fornece informações de erro detalhada, contextuais com o `IDispatch` e VTBL interfaces.  Para indicar que um manipulador de erros está disponível, você deve implementar a interface de **ISupportErrorInfo** .  
  
 Para ilustrar o mecanismo de tratamento de erro, suponha que as funções ClassWizard\- gerados usadas para implementar as exceções padrão do lançamento de suporte de distribuição.  A implementação de MFC de **IDispatch::Invoke** normalmente captura essas exceções e as converte em uma estrutura de EXCEPTINFO que é retornada por meio da chamada de `Invoke` .  No entanto, quando a interface de VTBL é usada, você é responsável para capturar exceções você mesmo.  Como exemplo de proteger seus métodos da interface dual e:  
  
```  
STDMETHODIMP CAutoClickDoc::XDualAClick::put_text(BSTR newText)  
{  
   METHOD_PROLOGUE(CAutoClickDoc, DualAClick)  
   TRY_DUAL(IID_IDualAClick)  
   {  
      // MFC automatically converts from Unicode BSTR to   
      // Ansi CString, if necessary...  
      pThis->m_str = newText;  
      return NOERROR;  
   }  
   CATCH_ALL_DUAL  
}  
```  
  
 `CATCH_ALL_DUAL` usa para retornar o código de erro correto quando ocorre uma exceção.  `CATCH_ALL_DUAL` converte uma exceção MFC nas informações de tratamento de erro de Automação OLE usando a interface de **ICreateErrorInfo** . \(Uma macro de `CATCH_ALL_DUAL` de exemplo esteja no arquivo MFCDUAL.H no exemplo de [ACDUAL](../top/visual-cpp-samples.md) .  A função que chama para tratar exceções, `DualHandleException`, está no arquivo MFCDUAL.CPP.\) `CATCH_ALL_DUAL` determina o código de erro a ser retornada com base no tipo de exceção gerada:  
  
-   [COleDispatchException](../Topic/COleDispatchException%20Class.md) – nesse caso, `HRESULT` é construído usando o seguinte código:  
  
    ```  
    hr = MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF,   
                               (e->m_wCode + 0x200));  
    ```  
  
     Isso cria um específico de `HRESULT` à interface que provocou a exceção.  O código de erro é deslocado por 0x200 para evitar todos os conflitos com `HRESULT`definido pelo sistema s para interfaces OLE padrão.  
  
-   [CMemoryException](../mfc/reference/cmemoryexception-class.md) – nesse caso, `E_OUTOFMEMORY` é retornado.  
  
-   Alguma outra exceção – nesse caso, `E_UNEXPECTED` é retornado.  
  
 Para indicar que o manipulador de erro de Automação OLE é usado, você também deve implementar a interface de **ISupportErrorInfo** .  
  
 Primeiramente, adicione o código à definição de classe de automação para deseja mostrá\-la que oferece suporte a **ISupportErrorInfo**.  
  
 Em seguida, adicione o código no mapa da interface da sua classe de automação para associar a classe de implementação de **ISupportErrorInfo** com o mecanismo de `QueryInterface` MFC.  A instrução de `INTERFACE_PART` corresponde a classe definida para **ISupportErrorInfo**.  
  
 Finalmente, implemente a classe definida para dar suporte a **ISupportErrorInfo**.  
  
 \(O exemplo de [ACDUAL](../top/visual-cpp-samples.md) contém três macros para ajudar executa essas três etapas, `DECLARE_DUAL_ERRORINFO`, `DUAL_ERRORINFO_PART`, e `IMPLEMENT_DUAL_ERRORINFO`, contido em qualquer MFCDUAL.H.\)  
  
 O exemplo a seguir implementa uma classe definida para dar suporte a **ISupportErrorInfo**.  `CAutoClickDoc` é o nome da sua classe de automação e `IID_IDualAClick` é **IID** para a interface que é a origem dos erros relatados pelo objeto de erro de Automação OLE:  
  
```  
STDMETHODIMP_(ULONG) CAutoClickDoc::XSupportErrorInfo::AddRef()   
{  
   METHOD_PROLOGUE(CAutoClickDoc, SupportErrorInfo)   
   return pThis->ExternalAddRef();   
}   
STDMETHODIMP_(ULONG) CAutoClickDoc::XSupportErrorInfo::Release()   
{   
   METHOD_PROLOGUE(CAutoClickDoc, SupportErrorInfo)   
   return pThis->ExternalRelease();   
}   
STDMETHODIMP CAutoClickDoc::XSupportErrorInfo::QueryInterface(   
   REFIID iid, LPVOID* ppvObj)   
{   
   METHOD_PROLOGUE(CAutoClickDoc, SupportErrorInfo)   
   return pThis->ExternalQueryInterface(&iid, ppvObj);   
}   
STDMETHODIMP CAutoClickDoc::XSupportErrorInfo::InterfaceSupportsErrorInfo(   
   REFIID iid)   
{   
   METHOD_PROLOGUE(CAutoClickDoc, SupportErrorInfo)   
   return (iid == IID_IDualAClick) ? S_OK : S_FALSE;   
}  
```  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)