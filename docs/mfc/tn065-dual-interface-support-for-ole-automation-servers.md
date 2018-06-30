---
title: 'TN065: Suporte de Interface dupla para servidores de automação OLE | Microsoft Docs'
ms.custom: ''
ms.date: 06/28/2018
ms.technology:
- cpp-mfc
ms.topic: conceptual
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e30be46aeab92f63f1b4cba593cda52bf9aeef9a
ms.sourcegitcommit: 208d445fd7ea202de1d372d3f468e784e77bd666
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/29/2018
ms.locfileid: "37122177"
---
# <a name="tn065-dual-interface-support-for-ole-automation-servers"></a>TN065: suporte para interface dupla para servidores de automação OLE

> [!NOTE]
> A Observação técnica a seguir não foi atualizada desde que ele foi incluído primeiro na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação on-line.

Esta anotação discute como adicionar suporte de interface dupla para um aplicativo de servidor com base em MFC de automação OLE. O [ACDUAL](../visual-cpp-samples.md) exemplo ilustra o suporte de interface dupla, e o código de exemplo essa observação é realizado de ACDUAL. As macros descritas nesta nota, como DECLARE_DUAL_ERRORINFO, DUAL_ERRORINFO_PART e IMPLEMENT_DUAL_ERRORINFO, fazem parte do exemplo de ACDUAL e podem ser encontradas em MFCDUAL. H.

## <a name="dual-interfaces"></a>Interfaces duplas

Embora a automação OLE permitem que você implemente um `IDispatch` interface, uma interface VTBL ou uma interface dupla (que abrange ambos), a Microsoft recomenda que você implemente as interfaces duplas para todos os objetos de automação OLE de exposto. Interfaces duplas tem vantagens significativas sobre `IDispatch`-somente ou somente VTBL interfaces:

- Associação podem ocorrer em tempo de compilação por meio da interface VTBL ou em tempo de execução por meio de `IDispatch`.

- Controladores de automação OLE que podem usar a interface VTBL podem se beneficiar de melhor desempenho.

- Controladores de automação OLE existentes que usam o `IDispatch` interface continuarão a funcionar.

- A interface VTBL é mais fácil de chamada de C++.

- Interfaces duplas são necessárias para compatibilidade com recursos de suporte de objeto do Visual Basic.

## <a name="adding-dual-interface-support-to-a-ccmdtarget-based-class"></a>Adicionando suporte a Interface dupla a uma classe com base em CCmdTarget

Uma interface dupla é apenas uma interface personalizada derivada de `IDispatch`. A maneira mais simples de implementar suporte de interface dupla em um `CCmdTarget`-baseado em classe é implementam primeiro a distribuição normal de interface em sua classe usando MFC e ClassWizard, em seguida, adicionar a interface personalizada mais tarde. A maior parte do tempo, sua implementação de interface personalizada simplesmente delegará para o MFC `IDispatch` implementação.

Primeiro, modifique o arquivo ODL do seu servidor para definir as interfaces duplas de seus objetos. Para definir uma interface dupla, você deve usar uma declaração de interface, em vez do `DISPINTERFACE` instrução que geram os assistentes do Visual C++. Em vez de remover existente `DISPINTERFACE` instrução, adicionar uma nova declaração de interface. Mantendo o `DISPINTERFACE` formulário, que você pode continuar a usar ClassWizard para adicionar propriedades e métodos para o objeto, mas você deve adicionar os equivalentes de propriedades e métodos para sua declaração de interface.

Uma declaração de interface para uma interface dupla deve ter o *OLEAUTOMATION* e *DUAL* atributos e a interface devem ser derivado de `IDispatch`. Você pode usar o [GUIDGEN](../visual-cpp-samples.md) amostra para criar um **IID** para a interface dupla:

```IDL
[ uuid(0BDD0E81-0DD7-11cf-BBA8-444553540000), // IID_IDualAClick
    oleautomation,
    dual
]
interface IDualAClick : IDispatch
    {
    };
```

Uma vez que a declaração de interface em vigor, começar a adicionar entradas para os métodos e propriedades. Interfaces duplas, você precisa reorganizar as listas de parâmetros para que seus métodos e as funções do acessador de propriedade na interface dupla retornam um **HRESULT** e passar valores de retorno como parâmetros com os atributos `[retval,out]`. Lembre-se de que para as propriedades, você precisará adicionar uma leitura (`propget`) e gravar (`propput`) acesso de função com a mesma id. Por exemplo:

```IDL
[propput, id(1)] HRESULT text([in] BSTR newText);
[propget, id(1)] HRESULT text([out, retval] BSTR* retval);
```

Depois que seus métodos e propriedades são definidas, você precisa adicionar uma referência para a declaração de interface na instrução coclass. Por exemplo:

```IDL
[ uuid(4B115281-32F0-11cf-AC85-444553540000) ]
coclass Document
{
    dispinterface IAClick;
    [default] interface IDualAClick;
};
```

Depois que o arquivo ODL tiver sido atualizado, use o mecanismo de mapa de interface do MFC para definir uma classe de implementação para a interface dupla em sua classe de objeto e verifique as entradas correspondentes no MFC `QueryInterface` mecanismo. Você precisa de uma entrada no `INTERFACE_PART` bloco para cada entrada na declaração de interface do ODL mais as entradas para uma interface de expedição. Cada entrada ODL com o *propput* atributo precisa de uma função chamada `put_propertyname`. Cada entrada com o *propget* atributo precisa de uma função chamada `get_propertyname`.

Para definir uma classe de implementação para a sua interface dupla, adicione um `DUAL_INTERFACE_PART` bloco à sua definição de classe do objeto. Por exemplo:

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

Para conectar-se a interface dupla do MFC [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms687230) mecanismo, adicione um `INTERFACE_PART` entrada para mapa de interface:

```cpp
BEGIN_INTERFACE_MAP(CAutoClickDoc, CDocument)
    INTERFACE_PART(CAutoClickDoc, DIID_IAClick, Dispatch)
    INTERFACE_PART(CAutoClickDoc, IID_IDualAClick, DualAClick)
END_INTERFACE_MAP()
```

Em seguida, você precisa preencher a implementação da interface. A maior parte do tempo, você poderá delegar a MFC existente `IDispatch` implementação. Por exemplo:

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

Para funções do acessador de propriedade e métodos do objeto, você precisa preencher a implementação. As funções de método e propriedade geralmente podem delegar para os métodos gerados usando ClassWizard. No entanto, se você definir as propriedades para acessar variáveis diretamente, você precisa escrever o código para o valor de get/put para a variável. Por exemplo:

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

## <a name="passing-dual-interface-pointers"></a>Ponteiros de Interface dupla de passagem

Passar o ponteiro de interface dupla não é simples, especialmente se você precisar chamar `CCmdTarget::FromIDispatch`. `FromIDispatch` funciona apenas em MFC `IDispatch` ponteiros. Uma maneira de resolver esse problema é a consulta para o original `IDispatch` ponteiro conjunto backup pelo MFC e passar esse ponteiro para funções que precisam dela. Por exemplo:

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

Antes de passar um ponteiro de volta por meio do método de interface dupla, talvez seja necessário convertê-lo de MFC `IDispatch` ponteiro para o ponteiro de interface dupla. Por exemplo:

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

## <a name="registering-the-applications-type-library"></a>Ao registrar a biblioteca de tipo do aplicativo

AppWizard não gera código para registrar a biblioteca de tipos de um aplicativo servidor de automação OLE com o sistema. Existem outras maneiras de registrar a biblioteca de tipos, é conveniente para que o aplicativo registrar a biblioteca de tipos, quando está atualizando as informações de tipo OLE, ou seja, sempre que o aplicativo for executado autônomo.

Para registrar a biblioteca de tipos aplicativo sempre que o aplicativo for executado autônomo:

- Inclua AFXCTL. H em seu padrão inclui o arquivo de cabeçalho STDAFX. H, para acessar a definição de `AfxOleRegisterTypeLib` função.

- Em seu aplicativo `InitInstance` funcionar, localize a chamada para `COleObjectFactory::UpdateRegistryAll`. Seguindo essa chamada, adicione uma chamada para `AfxOleRegisterTypeLib`, especificando o **LIBID** correspondente à sua biblioteca de tipos, juntamente com o nome da sua biblioteca de tipo:

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

## <a name="modifying-project-build-settings-to-accommodate-type-library-changes"></a>Modificando configurações de compilação do projeto para acomodar alterações de tipo de biblioteca

Para modificar configurações de compilação de um projeto para que um arquivo de cabeçalho que contém **UUID** definições é gerado pelo MkTypLib sempre que a biblioteca de tipos é reconstruída:

1. No **criar** menu, clique em **configurações**e, em seguida, selecione o arquivo ODL da lista de arquivos para cada configuração.

2. Clique o **tipos OLE** guia e especifique um nome de arquivo de **cabeçalho de saída** campo de nome de arquivo. Use um nome de arquivo não está sendo usado por seu projeto, porque MkTypLib substituirá qualquer arquivo existente. Clique em **Okey** para fechar o **configurações da compilação** caixa de diálogo.

Para adicionar o **UUID** definições do arquivo de cabeçalho gerado MkTypLib ao seu projeto:

1. Incluir o MkTypLib gerado pelo arquivo de cabeçalho no seu padrão inclui o arquivo de cabeçalho STDAFX. H.

2. Crie um novo arquivo, INITIIDS. CPP e adicioná-lo ao seu projeto. Nesse arquivo, inclua o arquivo de cabeçalho gerado MkTypLib após incluindo OLE2. H e INITGUID. H:

    ```cpp
    // initIIDs.c: defines IIDs for dual interfaces
    // This must not be built with precompiled header.
    #include <ole2.h>
    #include <initguid.h>
    #include "acdual.h"
    ```

3. Sobre o **criar** menu, clique em **configurações**e, em seguida, selecione INITIIDS. CPP da lista de arquivos para cada configuração.

4. Clique o **C++** , clique em categoria **cabeçalhos pré-compilados**e selecione o **não usar cabeçalhos pré-compilados** botão de opção. Clique em Okey para fechar o **configurações da compilação** caixa de diálogo.

## <a name="specifying-the-correct-object-class-name-in-the-type-library"></a>Especificando o nome da classe de objeto correto na biblioteca de tipos

Os assistentes fornecidos com o Visual C++ incorretamente usam o nome da classe de implementação para especificar coclass no arquivo ODL do servidor para classes instanciável OLE. Enquanto isso funcione, o nome da classe de implementação provavelmente não é o nome de classe que deseja que os usuários do seu objeto a ser usado. Para especificar o nome correto, abra o arquivo ODL, localize cada instrução coclass e substitua o nome da classe de implementação com o nome externo correto.

Observe que, quando a instrução coclass for alterado, os nomes de variáveis de **CLSID**s no arquivo de cabeçalho gerado MkTypLib será alterada de acordo. Você precisará atualizar seu código para usar os novos nomes de variável.

## <a name="handling-exceptions-and-the-automation-error-interfaces"></a>Tratamento de exceções e as Interfaces de erro de automação

Métodos e funções do acessador de propriedade de seu objeto de automação podem ocasionar exceções. Se assim, você deve tratá-los em sua implementação de interface dupla e passar informações sobre a exceção para o controlador por meio da interface de tratamento de erros de automação OLE, `IErrorInfo`. Essa interface fornece para obter informações de erro detalhadas e contextuais ambas `IDispatch` e VTBL interfaces. Para indicar que um manipulador de erros estiver disponível, você deve implementar o `ISupportErrorInfo` interface.

Para ilustrar o mecanismo de tratamento de erros, suponha que as funções gerado ClassWizard usadas para implementar o suporte de expedição padrão lançam exceções. A implementação do MFC de `IDispatch::Invoke` normalmente captura essas exceções e converte-os em uma estrutura EXCEPTINFO que é retornada por meio de `Invoke` chamar. No entanto, quando VTBL interface é usada, você é responsável por capturando as exceções por conta própria. Como um exemplo de proteção de seus métodos de interface dupla:

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

`CATCH_ALL_DUAL` cuida de retornar o código de erro corretas quando ocorre uma exceção. `CATCH_ALL_DUAL` Converte uma exceção de MFC em informações de tratamento de erros de automação OLE usando o `ICreateErrorInfo` interface. (Um exemplo `CATCH_ALL_DUAL` macro está no arquivo MFCDUAL. H no [ACDUAL](../visual-cpp-samples.md) exemplo. A função chama para lidar com exceções, `DualHandleException`, está no arquivo MFCDUAL. CPP). `CATCH_ALL_DUAL` determina o código de erro retornado com base no tipo de exceção que ocorreu:

- [COleDispatchException](../mfc/reference/coledispatchexception-class.md) - nesse caso, `HRESULT` é construído usando o código a seguir:

    ```cpp
    hr = MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, (e->m_wCode + 0x200));
    ```

     Isso cria um `HRESULT` específico para a interface que provocou a exceção. O código de erro tem um deslocamento de 0x200 para evitar conflitos com definidas pelo sistema `HRESULT`s para as interfaces OLE padrão.

- [CMemoryException](../mfc/reference/cmemoryexception-class.md) - nesse caso, `E_OUTOFMEMORY` será retornado.

- Qualquer outra exceção - nesse caso, `E_UNEXPECTED` será retornado.

Para indicar que o manipulador de erro de automação OLE é usado, você também deve implementar o `ISupportErrorInfo` interface.

Primeiro, adicione código para sua definição de classe de automação para mostrar que ele oferece suporte a `ISupportErrorInfo`.

Em seguida, adicione código ao mapa de interface da sua classe de automação para associar o `ISupportErrorInfo` classe de implementação com do MFC `QueryInterface` mecanismo. O `INTERFACE_PART` instrução corresponde a classe definida para `ISupportErrorInfo`.

Por fim, implementar a classe definida para dar suporte a `ISupportErrorInfo`.

(O [ACDUAL](../visual-cpp-samples.md) exemplo contém três macros para ajudar a fazer essas três etapas, `DECLARE_DUAL_ERRORINFO`, `DUAL_ERRORINFO_PART`, e `IMPLEMENT_DUAL_ERRORINFO`, todas contidas em MFCDUAL. H.)

O exemplo a seguir implementa uma classe definida para dar suporte a `ISupportErrorInfo`. `CAutoClickDoc` é o nome da sua classe de automação e `IID_IDualAClick` é o **IID** para a interface que é a origem de erros relatados por meio do objeto de erro de automação OLE:

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

[Observações técnicas por número](../mfc/technical-notes-by-number.md)  
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)  
