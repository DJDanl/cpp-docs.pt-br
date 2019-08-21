---
title: 'TN065: Suporte de interface dual para servidores de automação OLE'
ms.date: 06/28/2018
f1_keywords:
- vc.ole
helpviewer_keywords:
- dual interfaces [MFC], OLE Automation
- TN065 [MFC]
- ACDUAL sample [MFC]
- Automation servers [MFC], dual-interface support
ms.assetid: b5c8ed09-2f7f-483c-80fc-2a47ad896063
ms.openlocfilehash: 1508b5219f7bb7fd2e9c9a56c42c30bb99686804
ms.sourcegitcommit: 9d4ffb8e6e0d70520a1e1a77805785878d445b8a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/20/2019
ms.locfileid: "69630387"
---
# <a name="tn065-dual-interface-support-for-ole-automation-servers"></a>TN065: Suporte de interface dual para servidores de automação OLE

> [!NOTE]
> A observação técnica a seguir não foi atualizada desde que foi incluída pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizados ou incorretos. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice de documentação online.

Esta observação discute como adicionar suporte de interface dual a um aplicativo de servidor de automação OLE baseado em MFC. O exemplo [ACDUAL](../overview/visual-cpp-samples.md) ilustra o suporte de interface dupla, e o código de exemplo nesta observação é obtido do ACDUAL. As macros descritas nesta nota, como DECLARE_DUAL_ERRORINFO, DUAL_ERRORINFO_PART e IMPLEMENT_DUAL_ERRORINFO, fazem parte do exemplo ACDUAL e podem ser encontradas em MFCDUAL. T.

## <a name="dual-interfaces"></a>Interfaces duplas

Embora a automação OLE permita que você implemente uma `IDispatch` interface, uma interface VTBL ou uma interface dupla (que abrange ambas), a Microsoft recomenda enfaticamente que você implemente interfaces duplas para todos os objetos de automação OLE expostos. Interfaces duplas têm vantagens `IDispatch`significativas apenas ou interfaces somente VTBL:

- A associação pode ocorrer no momento da compilação por meio da interface VTBL ou em tempo de `IDispatch`execução até.

- Os controladores de automação OLE que podem usar a interface VTBL podem se beneficiar do desempenho melhorado.

- Controladores de automação OLE existentes que usam `IDispatch` a interface continuarão a funcionar.

- A interface VTBL é mais fácil de C++chamar.

- Interfaces duplas são necessárias para compatibilidade com recursos de suporte a objetos Visual Basic.

## <a name="adding-dual-interface-support-to-a-ccmdtarget-based-class"></a>Adicionando suporte de interface dual a uma classe baseada em CCmdTarget

Uma interface dupla é, na verdade, apenas uma interface `IDispatch`personalizada derivada de. A maneira mais simples de implementar o suporte de interface dual em `CCmdTarget`uma classe baseada em uma é implementar primeiro a interface de expedição normal em sua classe usando MFC e ClassWizard, em seguida, adicionar a interface personalizada mais tarde. Na maior parte, sua implementação de interface personalizada simplesmente será delegada de volta à `IDispatch` implementação do MFC.

Primeiro, modifique o arquivo ODL para o servidor para definir interfaces duplas para seus objetos. Para definir uma interface dupla, você deve usar uma instrução de interface, em vez `DISPINTERFACE` da instrução que os C++ assistentes do Visual geram. Em vez de remover a `DISPINTERFACE` instrução existente, adicione uma nova instrução de interface. Ao reter o formulário `DISPINTERFACE` , você pode continuar a usar o ClassWizard para adicionar propriedades e métodos ao seu objeto, mas você deve adicionar as propriedades e os métodos equivalentes à sua instrução de interface.

Uma instrução de interface para uma interface dupla deve ter os atributos *oleautomation* e *Dual* , e a interface deve ser derivada `IDispatch`de. Você pode usar o exemplo de [Guidgen](../overview/visual-cpp-samples.md) para criar um **IID** para a interface dupla:

```IDL
[ uuid(0BDD0E81-0DD7-11cf-BBA8-444553540000), // IID_IDualAClick
    oleautomation,
    dual
]
interface IDualAClick : IDispatch
    {
    };
```

Depois que a instrução de interface estiver em vigor, comece a adicionar entradas para os métodos e propriedades. Para interfaces duplas, você precisa reorganizar as listas de parâmetros para que seus métodos e funções de acessador de propriedade na interface dupla retornem um **HRESULT** e passem seus `[retval,out]`valores de retorno como parâmetros com os atributos. Lembre-se de que, para propriedades, será necessário adicionar uma função`propget`de acesso Read (`propput`) e Write () com a mesma ID. Por exemplo:

```IDL
[propput, id(1)] HRESULT text([in] BSTR newText);
[propget, id(1)] HRESULT text([out, retval] BSTR* retval);
```

Depois que os métodos e as propriedades forem definidos, você precisará adicionar uma referência à instrução de interface em sua instrução coclass. Por exemplo:

```IDL
[ uuid(4B115281-32F0-11cf-AC85-444553540000) ]
coclass Document
{
    dispinterface IAClick;
    [default] interface IDualAClick;
};
```

Depois que o arquivo ODL tiver sido atualizado, use o mecanismo de mapa de interface do MFC para definir uma classe de implementação para a interface dupla em sua classe de objeto e fazer `QueryInterface` as entradas correspondentes no mecanismo do MFC. Você precisa de uma entrada no `INTERFACE_PART` bloco para cada entrada na instrução de interface do ODL, além das entradas de uma interface de expedição. Cada entrada ODL com o atributo *propput* precisa de uma função `put_propertyname`chamada. Cada entrada com o atributo *propget* precisa de uma função `get_propertyname`chamada.

Para definir uma classe de implementação para sua interface dual, adicione `DUAL_INTERFACE_PART` um bloco à sua definição de classe de objeto. Por exemplo:

```cpp
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

Para conectar a interface dupla ao mecanismo de [QueryInterface](/windows/win32/com/queryinterface--navigating-in-an-object) do MFC, adicione `INTERFACE_PART` uma entrada ao mapa de interface:

```cpp
BEGIN_INTERFACE_MAP(CAutoClickDoc, CDocument)
    INTERFACE_PART(CAutoClickDoc, DIID_IAClick, Dispatch)
    INTERFACE_PART(CAutoClickDoc, IID_IDualAClick, DualAClick)
END_INTERFACE_MAP()
```

Em seguida, você precisa preencher a implementação da interface. Para a maior parte, você poderá delegar à implementação existente do MFC `IDispatch` . Por exemplo:

```cpp
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
    REFIID iid,
    LPVOID* ppvObj)
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
    UINT itinfo,
    LCID lcid,
    ITypeInfo FAR* FAR* pptinfo)
{
    METHOD_PROLOGUE(CAutoClickDoc, DualAClick)
    LPDISPATCH lpDispatch = pThis->GetIDispatch(FALSE);
    ASSERT(lpDispatch != NULL);

    return lpDispatch->GetTypeInfo(itinfo, lcid, pptinfo);
}

STDMETHODIMP CAutoClickDoc::XDualAClick::GetIDsOfNames(
    REFIID riid,
    OLECHAR FAR* FAR* rgszNames,
    UINT cNames,
    LCID lcid,
    DISPID FAR* rgdispid)
{
    METHOD_PROLOGUE(CAutoClickDoc, DualAClick)
    LPDISPATCH lpDispatch = pThis->GetIDispatch(FALSE);
    ASSERT(lpDispatch != NULL);

    return lpDispatch->GetIDsOfNames(riid, rgszNames, cNames, lcid, rgdispid);
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
    METHOD_PROLOGUE(CAutoClickDoc, DualAClick)
    LPDISPATCH lpDispatch = pThis->GetIDispatch(FALSE);
    ASSERT(lpDispatch != NULL);

    return lpDispatch->Invoke(dispidMember, riid, lcid,
        wFlags, pdispparams, pvarResult, pexcepinfo, puArgErr);
}
```

Para os métodos do objeto e as funções de acessador de propriedade, você precisa preencher a implementação. As funções de método e propriedade geralmente podem delegar de volta para os métodos gerados usando ClassWizard. No entanto, se você configurar propriedades para acessar variáveis diretamente, você precisará escrever o código para obter/colocar o valor na variável. Por exemplo:

```cpp
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

## <a name="passing-dual-interface-pointers"></a>Passando ponteiros de interface dupla

Passar o ponteiro de interface dupla não é simples, especialmente se você precisar chamar `CCmdTarget::FromIDispatch`. `FromIDispatch`funciona apenas em ponteiros `IDispatch` do MFC. Uma maneira de contornar isso é consultar o ponteiro original `IDispatch` configurado pelo MFC e passar esse ponteiro para funções que precisam dele. Por exemplo:

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

Antes de passar um ponteiro de volta pelo método de interface dual, talvez seja necessário convertê-lo do `IDispatch` ponteiro do MFC para o ponteiro de interface dupla. Por exemplo:

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

## <a name="registering-the-applications-type-library"></a>Registrando a biblioteca de tipos do aplicativo

AppWizard não gera código para registrar uma biblioteca de tipos de aplicativo de servidor de automação OLE com o sistema. Embora haja outras maneiras de registrar a biblioteca de tipos, é conveniente fazer com que o aplicativo registre a biblioteca de tipos quando estiver atualizando suas informações de tipo OLE, ou seja, sempre que o aplicativo for executado de forma autônoma.

Para registrar a biblioteca de tipos do aplicativo sempre que o aplicativo for executado de forma autônoma:

- Inclua AFXCTL. H em seu padrão inclui o arquivo de cabeçalho, STDAFX. H, para acessar a definição da `AfxOleRegisterTypeLib` função.

- Na função do `InitInstance` seu aplicativo, localize a chamada para `COleObjectFactory::UpdateRegistryAll`. Seguindo essa chamada, adicione uma chamada para `AfxOleRegisterTypeLib`, especificando o **LIBID** correspondente à sua biblioteca de tipos, junto com o nome da sua biblioteca de tipos:

    ```cpp
    // When a server application is launched stand-alone, it is a good idea
    // to update the system registry in case it has been damaged.
    m_server.UpdateRegistry(OAT_DISPATCH_OBJECT);

    COleObjectFactory::UpdateRegistryAll();

    // DUAL_SUPPORT_START
        // Make sure the type library is registered or dual interface won't work.
        AfxOleRegisterTypeLib(AfxGetInstanceHandle(),
            LIBID_ACDual,
            _T("AutoClik.TLB"));
    // DUAL_SUPPORT_END
    ```

## <a name="modifying-project-build-settings-to-accommodate-type-library-changes"></a>Modificando as configurações de compilação do projeto para acomodar alterações na biblioteca de tipos

Para modificar as configurações de Build de um projeto para que um arquivo de cabeçalho contendo definições de **UUID** seja gerado por MkTypLib sempre que a biblioteca de tipos for reconstruída:

1. No menu **Compilar** , clique em **configurações**e, em seguida, selecione o arquivo ODL na lista de arquivos para cada configuração.

2. Clique na guia **tipos OLE** e especifique um nome de arquivo no campo nome do arquivo do **cabeçalho de saída** . Use um nome de arquivo que ainda não esteja sendo usado pelo seu projeto, pois o MkTypLib substituirá qualquer arquivo existente. Clique em **OK** para fechar a caixa de diálogo **configurações de compilação** .

Para adicionar as definições de **UUID** do arquivo de cabeçalho gerado pelo MkTypLib ao seu projeto:

1. Inclua o arquivo de cabeçalho gerado pelo MkTypLib em seu arquivo de cabeçalho padrão include, *stdafx. h*.

2. Crie um novo arquivo, INITIIDS. CPP e adicione-o ao seu projeto. Nesse arquivo, inclua o arquivo de cabeçalho gerado pelo MkTypLib depois de incluir OLE2. H e INITGUID. T

    ```cpp
    // initIIDs.c: defines IIDs for dual interfaces
    // This must not be built with precompiled header.
    #include <ole2.h>
    #include <initguid.h>
    #include "acdual.h"
    ```

3. No menu **Compilar** , clique em **configurações**e, em seguida, selecione INITIIDS. CPP na lista de arquivos para cada configuração.

4. Clique na **C++** guia, clique em categoria **cabeçalhos pré-compilados**e selecione o botão de opção **não usar cabeçalhos pré** -compilados. Clique em OK para fechar a caixa de diálogo **configurações de compilação** .

## <a name="specifying-the-correct-object-class-name-in-the-type-library"></a>Especificando o nome da classe de objeto correto na biblioteca de tipos

Os assistentes fornecidos com o C++ Visual incorretamente usam o nome da classe de implementação para especificar a coclasse no arquivo ODL do servidor para classes OLE-creatable. Embora isso funcione, o nome da classe de implementação provavelmente não é o nome da classe que você deseja que os usuários do seu objeto usem. Para especificar o nome correto, abra o arquivo ODL, localize cada instrução coclass e substitua o nome da classe de implementação pelo nome externo correto.

Observe que, quando a instrução coclass é alterada, os nomes de variáveis de **CLSID**s no arquivo de cabeçalho gerado pelo MkTypLib serão alterados de acordo. Você precisará atualizar seu código para usar os novos nomes de variáveis.

## <a name="handling-exceptions-and-the-automation-error-interfaces"></a>Manipulando exceções e as interfaces de erro de automação

Os métodos do seu objeto de automação e as funções de acessador de propriedade podem gerar exceções. Nesse caso, você deve tratá-los em sua implementação de interface dupla e passar informações sobre a exceção de volta para o controlador por meio da interface de tratamento de `IErrorInfo`erros da automação OLE,. Essa interface fornece informações de erro contextuais detalhadas por meio `IDispatch` das interfaces e VTBL. Para indicar que um manipulador de erro está disponível, você deve implementar `ISupportErrorInfo` a interface.

Para ilustrar o mecanismo de tratamento de erros, suponha que as funções geradas pelo ClassWizard usadas para implementar o suporte de expedição padrão gerem exceções. A implementação do `IDispatch::Invoke` MFC normalmente captura essas exceções e as converte em uma estrutura EXCEPTINFO que é retornada por meio da `Invoke` chamada. No entanto, quando a interface VTBL é usada, você é responsável por capturar as exceções por conta própria. Como exemplo de proteção de seus métodos de interface dual:

```cpp
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

`CATCH_ALL_DUAL`Cuida da retomada do código de erro correto quando ocorre uma exceção. `CATCH_ALL_DUAL`Converte uma exceção MFC em informações de manipulação de erros da automação OLE `ICreateErrorInfo` usando a interface. (Uma macro `CATCH_ALL_DUAL` de exemplo está no arquivo MFCDUAL. H no exemplo de [ACDUAL](../overview/visual-cpp-samples.md) . A função que ele chama para manipular exceções `DualHandleException`, está no arquivo MFCDUAL. CPP.) `CATCH_ALL_DUAL` determina o código de erro a ser retornado com base no tipo de exceção que ocorreu:

- [COleDispatchException](../mfc/reference/coledispatchexception-class.md) – nesse caso, `HRESULT` é construído usando o seguinte código:

    ```cpp
    hr = MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, (e->m_wCode + 0x200));
    ```

   Isso cria um `HRESULT` específico para a interface que causou a exceção. O código de erro é compensado por 0x200 para evitar conflitos com s `HRESULT`definidos pelo sistema para interfaces OLE padrão.

- [CMemoryException](../mfc/reference/cmemoryexception-class.md) – nesse caso, `E_OUTOFMEMORY` é retornado.

- Qualquer outra exceção – nesse caso, `E_UNEXPECTED` é retornada.

Para indicar que o manipulador de erro de automação OLE é usado, você também deve `ISupportErrorInfo` implementar a interface.

Primeiro, adicione o código à sua definição de classe de automação para `ISupportErrorInfo`mostrar a ele suporte.

Em segundo lugar, adicione o código ao mapa de interface da sua classe `ISupportErrorInfo` de automação para associar a `QueryInterface` classe de implementação ao mecanismo do MFC. A `INTERFACE_PART` instrução corresponde à classe definida para `ISupportErrorInfo`.

Por fim, implemente a classe definida `ISupportErrorInfo`para dar suporte ao.

(O exemplo [ACDUAL](../overview/visual-cpp-samples.md) contém três macros para ajudar a executar essas três `DECLARE_DUAL_ERRORINFO`etapas `DUAL_ERRORINFO_PART`,, `IMPLEMENT_DUAL_ERRORINFO`e, todas contidas em MFCDUAL. H.)

O exemplo a seguir implementa uma classe definida para `ISupportErrorInfo`dar suporte ao. `CAutoClickDoc`é o nome da sua classe de automação `IID_IDualAClick` e é o **IID** para a interface que é a fonte de erros relatados por meio do objeto de erro de automação OLE:

```cpp
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
    REFIID iid,
    LPVOID* ppvObj)
{
    METHOD_PROLOGUE(CAutoClickDoc, SupportErrorInfo)
    return pThis->ExternalQueryInterface(&iid, ppvObj);
}

STDMETHODIMP CAutoClickDoc::XSupportErrorInfo::InterfaceSupportsErrorInfo(
    REFIID iid)
{
    METHOD_PROLOGUE(CAutoClickDoc, SupportErrorInfo)
    return (iid == IID_IDualAClick) S_OK : S_FALSE;
}
```

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
