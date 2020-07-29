---
title: 'TN038: implementação MFC-OLE IUnknown'
ms.date: 06/28/2018
helpviewer_keywords:
- aggregation macros [MFC]
- COM interfaces, base interface
- IUnknown interface
- END_INTERFACE_MAP macro [MFC]
- TN038
- BEGIN_INTERFACE_PART macro [MFC]
- DECLARE_INTERFACE_MAP macro [MFC]
- BEGIN_INTERFACE_MAP macro [MFC]
- OLE [MFC], implementing IUnknown interface
- METHOD_PROLOGUE macro [MFC]
- STDMETHOD macro [MFC]
- END_INTERFACE_PART macro [MFC]
- INTERFACE_PART macro
ms.assetid: 19d946ba-beaf-4881-85c6-0b598d7f6f11
ms.openlocfilehash: 83166b32a20b8d24f748f85946caa01dbc76d4d0
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230435"
---
# <a name="tn038-mfcole-iunknown-implementation"></a>TN038: implementação de IUnknown MFC/OLE

> [!NOTE]
> A observação técnica a seguir não foi atualizada desde que foi incluída pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizados ou incorretos. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice de documentação online.

No coração do OLE 2 está o "Component Object Model OLE" ou COM. COM define um padrão para como os objetos cooperativos se comunicam entre si. Isso inclui os detalhes de como um "objeto" se parece, incluindo como os métodos são expedidos em um objeto. COM também define uma classe base, da qual todas as classes compatíveis COM COM são derivadas. Essa classe base é [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown). Embora a interface [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) seja conhecida como uma classe C++, com não é específica para qualquer linguagem — ela pode ser implementada em C, Pascal ou em qualquer outra linguagem que possa dar suporte ao layout binário de um objeto com.

OLE refere-se a todas as classes derivadas de [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) como "interfaces". Essa é uma distinção importante, uma vez que uma "interface", como [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) , carrega-a sem implementação. Ele simplesmente define o protocolo pelo qual os objetos se comunicam, não as especificidades do que essas implementações fazem. Isso é razoável para um sistema que permite a máxima flexibilidade. É o trabalho do MFC implementar um comportamento padrão para programas MFC/C++.

Para entender a implementação de [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) do MFC, você deve primeiro entender o que é essa interface. Uma versão simplificada de [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) é definida abaixo:

```cpp
class IUnknown
{
public:
    virtual HRESULT QueryInterface(REFIID iid, void** ppvObj) = 0;
    virtual ULONG AddRef() = 0;
    virtual ULONG Release() = 0;
};
```

> [!NOTE]
> Determinados detalhes de Convenção de chamada necessários, como **`__stdcall`** são deixados para esta ilustração.

As funções de membro [AddRef](/windows/win32/api/unknwn/nf-unknwn-iunknown-addref) e [Release](/windows/win32/api/unknwn/nf-unknwn-iunknown-release) controlam o gerenciamento de memória do objeto. COM usa um esquema de contagem de referência para manter o controle dos objetos. Um objeto nunca é referenciado diretamente como você faria em C++. Em vez disso, os objetos COM são sempre referenciados por meio de um ponteiro. Para liberar o objeto quando o proprietário é feito usando-o, o membro de [liberação](/windows/win32/api/unknwn/nf-unknwn-iunknown-release) do objeto é chamado (em oposição ao uso de Delete do operador, como seria feito para um objeto C++ tradicional). O mecanismo de contagem de referência permite que várias referências a um único objeto sejam gerenciadas. Uma implementação de [AddRef](/windows/win32/api/unknwn/nf-unknwn-iunknown-addref) e [Release](/windows/win32/api/unknwn/nf-unknwn-iunknown-release) mantém uma contagem de referência no objeto — o objeto não é excluído até que sua contagem de referência chegue a zero.

[AddRef](/windows/win32/api/unknwn/nf-unknwn-iunknown-addref) e [Release](/windows/win32/api/unknwn/nf-unknwn-iunknown-release) são razoavelmente simples do ponto de vista da implementação. Aqui está uma implementação trivial:

```cpp
ULONG CMyObj::AddRef()
{
    return ++m_dwRef;
}

ULONG CMyObj::Release()
{
    if (--m_dwRef == 0)
    {
        delete this;
        return 0;
    }
    return m_dwRef;
}
```

A função de membro [QueryInterface](/windows/win32/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) é um pouco mais interessante. Não é muito interessante ter um objeto cujas únicas funções membro sejam [AddRef](/windows/win32/api/unknwn/nf-unknwn-iunknown-addref) e [Release](/windows/win32/api/unknwn/nf-unknwn-iunknown-release) — seria interessante dizer ao objeto fazer mais coisas que o [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) fornece. É aí que [QueryInterface](/windows/win32/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) é útil. Ele permite que você obtenha uma "interface" diferente no mesmo objeto. Essas interfaces geralmente são derivadas de [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) e adicionam funcionalidade adicional adicionando novas funções de membro. Interfaces COM nunca têm variáveis de membro declaradas na interface, e todas as funções de membro são declaradas como virtuais puras. Por exemplo:

```cpp
class IPrintInterface : public IUnknown
{
public:
    virtual void PrintObject() = 0;
};
```

Para obter um IPrintInterface se você tiver apenas um [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown), chame [QueryInterface](/windows/win32/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) usando o `IID` do `IPrintInterface` . Um `IID` é um número de 128 bits que identifica exclusivamente a interface. Há um `IID` para cada interface que você ou o OLE define. Se *punk* for um ponteiro para um objeto [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) , o código para recuperar um IPrintInterface dele poderá ser:

```cpp
IPrintInterface* pPrint = NULL;
if (pUnk->QueryInterface(IID_IPrintInterface, (void**)&pPrint) == NOERROR)
{
    pPrint->PrintObject();
    pPrint->Release();
    // release pointer obtained via QueryInterface
}
```

Isso parece bastante fácil, mas como você implementaria um objeto que dá suporte à interface IPrintInterface e [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) nesse caso, é simples, uma vez que o IPrintInterface é derivado diretamente de [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) — a implementação de IPrintInterface, [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) é suportada automaticamente. Por exemplo:

```cpp
class CPrintObj : public CPrintInterface
{
    virtual HRESULT QueryInterface(REFIID iid, void** ppvObj);
    virtual ULONG AddRef();
    virtual ULONG Release();
    virtual void PrintObject();
};
```

As implementações de [AddRef](/windows/win32/api/unknwn/nf-unknwn-iunknown-addref) e [Release](/windows/win32/api/unknwn/nf-unknwn-iunknown-release) seriam exatamente iguais às implementadas acima. `CPrintObj::QueryInterface`teria uma aparência semelhante a esta:

```cpp
HRESULT CPrintObj::QueryInterface(REFIID iid, void FAR* FAR* ppvObj)
{
    if (iid == IID_IUnknown || iid == IID_IPrintInterface)
    {
        *ppvObj = this;
        AddRef();
        return NOERROR;
    }
    return E_NOINTERFACE;
}
```

Como você pode ver, se o identificador de interface (IID) for reconhecido, um ponteiro será retornado ao seu objeto; caso contrário, ocorrerá um erro. Observe também que um [QueryInterface](/windows/win32/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) bem-sucedido resulta em um [AddRef](/windows/win32/api/unknwn/nf-unknwn-iunknown-addref)implícito. É claro que você também precisaria implementar CEditObj::P rimir. Isso é simples porque o IPrintInterface era diretamente derivado da interface [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) . No entanto, se você quisesse dar suporte a duas interfaces diferentes, ambas derivadas de [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown), considere o seguinte:

```cpp
class IEditInterface : public IUnkown
{
public:
    virtual void EditObject() = 0;
};
```

Embora haja várias maneiras diferentes de implementar uma classe que dê suporte a IEditInterface e IPrintInterface, incluindo o uso de uma herança de múltiplas C++, essa observação se concentrará no uso de classes aninhadas para implementar essa funcionalidade.

```cpp
class CEditPrintObj
{
public:
    CEditPrintObj();

    HRESULT QueryInterface(REFIID iid, void**);
    ULONG AddRef();
    ULONG Release();
    DWORD m_dwRef;

    class CPrintObj : public IPrintInterface
    {
    public:
        CEditPrintObj* m_pParent;
        virtual HRESULT QueryInterface(REFIID iid, void** ppvObj);
        virtual ULONG AddRef();
        virtual ULONG Release();
    } m_printObj;

    class CEditObj : public IEditInterface
    {
    public:
        CEditPrintObj* m_pParent;
        virtual ULONG QueryInterface(REFIID iid, void** ppvObj);
        virtual ULONG AddRef();
        virtual ULONG Release();
    } m_editObj;
};
```

A implementação inteira está incluída abaixo:

```cpp
CEditPrintObj::CEditPrintObj()
{
    m_editObj.m_pParent = this;
    m_printObj.m_pParent = this;
}

ULONG CEditPrintObj::AddRef()
{
    return ++m_dwRef;
}

CEditPrintObj::Release()
{
    if (--m_dwRef == 0)
    {
        delete this;
        return 0;
    }
    return m_dwRef;
}

HRESULT CEditPrintObj::QueryInterface(REFIID iid, void** ppvObj)
{
    if (iid == IID_IUnknown || iid == IID_IPrintInterface)
    {
        *ppvObj = &m_printObj;
        AddRef();
        return NOERROR;
    }
    else if (iid == IID_IEditInterface)
    {
        *ppvObj = &m_editObj;
        AddRef();
        return NOERROR;
    }
    return E_NOINTERFACE;
}

ULONG CEditPrintObj::CEditObj::AddRef()
{
    return m_pParent->AddRef();
}

ULONG CEditPrintObj::CEditObj::Release()
{
    return m_pParent->Release();
}

HRESULT CEditPrintObj::CEditObj::QueryInterface(REFIID iid, void** ppvObj)
{
    return m_pParent->QueryInterface(iid, ppvObj);
}

ULONG CEditPrintObj::CPrintObj::AddRef()
{
    return m_pParent->AddRef();
}

ULONG CEditPrintObj::CPrintObj::Release()
{
    return m_pParent->Release();
}

HRESULT CEditPrintObj::CPrintObj::QueryInterface(REFIID iid, void** ppvObj)
{
    return m_pParent->QueryInterface(iid, ppvObj);
}
```

Observe que a maior parte da implementação [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) é colocada na classe CEditPrintObj em vez de duplicar o código em CEditPrintObj:: CEditObj e CEditPrintObj:: CPrintObj. Isso reduz a quantidade de código e evita bugs. O ponto principal aqui é que, da interface IUnknown, é possível chamar [QueryInterface](/windows/win32/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) para recuperar qualquer interface à qual o objeto possa dar suporte e de cada uma dessas interfaces é possível fazer o mesmo. Isso significa que todas as funções de [QueryInterface](/windows/win32/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) disponíveis de cada interface devem se comportar exatamente da mesma maneira. Para que esses objetos inseridos chamem a implementação no "objeto externo", um ponteiro de apoio é usado (m_pParent). O ponteiro de m_pParent é inicializado durante o Construtor CEditPrintObj. Em seguida, você implementará CEditPrintObj:: CPrintObj::P rintObject e CEditPrintObj:: CEditObj:: EditObject também. Um pouco de código foi adicionado para adicionar um recurso — a capacidade de editar o objeto. Felizmente, é muito incomum que as interfaces tenham apenas uma única função de membro (embora isso aconteça) e, nesse caso, o EditObject e o FileObject normalmente seriam combinados em uma única interface.

Isso é uma grande quantidade de explicações e muitos códigos para um cenário tão simples. As classes MFC/OLE fornecem uma alternativa mais simples. A implementação do MFC usa uma técnica semelhante à maneira como as mensagens do Windows são encapsuladas com mapas de mensagens. Esse recurso é chamado de *mapas de interface* e é discutido na próxima seção.

## <a name="mfc-interface-maps"></a>Mapas da interface MFC

O MFC/OLE inclui uma implementação de "mapas de interface" semelhante aos "mapas de mensagens" e "mapas de expedição" do MFC em conceito e execução. Os principais recursos dos mapas de interface do MFC são os seguintes:

- Uma implementação padrão de [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown), incorporada à `CCmdTarget` classe.

- Manutenção da contagem de referência, modificada por [AddRef](/windows/win32/api/unknwn/nf-unknwn-iunknown-addref) e [versão](/windows/win32/api/unknwn/nf-unknwn-iunknown-release)

- Implementação controlada por dados de [QueryInterface](/windows/win32/api/unknwn/nf-unknwn-iunknown-queryinterface(q))

Além disso, os mapas de interface dão suporte aos seguintes recursos avançados:

- Suporte à criação de objetos COM agregáveis

- Suporte ao uso de objetos de agregação na implementação de um objeto COM

- A implementação é conectável e extensível

Para obter mais informações sobre agregação, consulte o tópico de [agregação](/windows/win32/com/aggregation) .

O suporte ao mapa de interface do MFC tem raiz na `CCmdTarget` classe. `CCmdTarget`contagem de referência "*tem-um*", bem como todas as funções de membro associadas à implementação [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) (a contagem de referência, por exemplo, está em `CCmdTarget` ). Para criar uma classe que ofereça suporte a OLE COM, você deriva uma classe de `CCmdTarget` e usa várias macros, bem como funções de membro do `CCmdTarget` para implementar as interfaces desejadas. A implementação do MFC usa classes aninhadas para definir cada implementação de interface da mesma forma que o exemplo acima. Isso é simplificado com uma implementação padrão de IUnknown, bem como várias macros que eliminam parte do código repetitivo.

## <a name="interface-map-basics"></a>Noções básicas do mapa de interface

### <a name="to-implement-a-class-using-mfcs-interface-maps"></a>Para implementar uma classe usando mapas de interface do MFC

1. Derive uma classe direta ou indiretamente a partir do `CCmdTarget` .

2. Use a `DECLARE_INTERFACE_MAP` função na definição de classe derivada.

3. Para cada interface à qual você deseja dar suporte, use as macros BEGIN_INTERFACE_PART e END_INTERFACE_PART na definição de classe.

4. No arquivo de implementação, use as macros BEGIN_INTERFACE_MAP e END_INTERFACE_MAP para definir o mapa de interface da classe.

5. Para cada IID com suporte, use a macro INTERFACE_PART entre as macros BEGIN_INTERFACE_MAP e END_INTERFACE_MAP para mapear essa IID para uma "parte" específica de sua classe.

6. Implemente cada uma das classes aninhadas que representam as interfaces às quais você dá suporte.

7. Use a macro METHOD_PROLOGUE para acessar o objeto pai `CCmdTarget` derivado.

8. [AddRef](/windows/win32/api/unknwn/nf-unknwn-iunknown-addref), [Release](/windows/win32/api/unknwn/nf-unknwn-iunknown-release)e [QueryInterface](/windows/win32/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) podem delegar à `CCmdTarget` implementação dessas funções ( `ExternalAddRef` , `ExternalRelease` e `ExternalQueryInterface` ).

O exemplo de CPrintEditObj acima poderia ser implementado da seguinte maneira:

```cpp
class CPrintEditObj : public CCmdTarget
{
public:
    // member data and member functions for CPrintEditObj go here

// Interface Maps
protected:
    DECLARE_INTERFACE_MAP()

    BEGIN_INTERFACE_PART(EditObj, IEditInterface)
        STDMETHOD_(void, EditObject)();
    END_INTERFACE_PART(EditObj)

    BEGIN_INTERFACE_PART(PrintObj, IPrintInterface)
        STDMETHOD_(void, PrintObject)();
    END_INTERFACE_PART(PrintObj)
};
```

A declaração acima cria uma classe derivada de `CCmdTarget` . A macro DECLARE_INTERFACE_MAP informa à estrutura que essa classe terá um mapa de interface personalizado. Além disso, as macros BEGIN_INTERFACE_PART e END_INTERFACE_PART definem classes aninhadas, nesse caso, com os nomes CEditObj e CPrintObj (o X é usado apenas para diferenciar as classes aninhadas das classes globais que começam com "C" e classes de interface que começam com "I"). Dois membros aninhados dessas classes são criados: m_CEditObj e m_CPrintObj, respectivamente. As macros declaram automaticamente as funções [AddRef](/windows/win32/api/unknwn/nf-unknwn-iunknown-addref), [Release](/windows/win32/api/unknwn/nf-unknwn-iunknown-release)e [QueryInterface](/windows/win32/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) ; Portanto, você declara apenas as funções específicas para esta interface: EditObject e FileObject (a macro OLE STDMETHOD é usada para que **_stdcall** e palavras-chave virtuais sejam fornecidas conforme apropriado para a plataforma de destino).

Para implementar o mapa de interface para esta classe:

```cpp
BEGIN_INTERFACE_MAP(CPrintEditObj, CCmdTarget)
    INTERFACE_PART(CPrintEditObj, IID_IPrintInterface, PrintObj)
    INTERFACE_PART(CPrintEditObj, IID_IEditInterface, EditObj)
END_INTERFACE_MAP()
```

Isso conecta o IID_IPrintInterface IID com m_CPrintObj e IID_IEditInterface com m_CEditObj respectivamente. A `CCmdTarget` implementação de [QueryInterface](/windows/win32/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) ( `CCmdTarget::ExternalQueryInterface` ) usa esse mapa para retornar ponteiros para m_CPrintObj e m_CEditObj quando solicitado. Não é necessário incluir uma entrada para `IID_IUnknown` ; a estrutura usará a primeira interface no mapa (nesse caso, m_CPrintObj) quando `IID_IUnknown` for solicitado.

Embora a macro BEGIN_INTERFACE_PART declarada automaticamente as funções [AddRef](/windows/win32/api/unknwn/nf-unknwn-iunknown-addref), [Release](/windows/win32/api/unknwn/nf-unknwn-iunknown-release) e [QueryInterface](/windows/win32/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) para você, você ainda precisa implementá-las:

```cpp
ULONG FAR EXPORT CEditPrintObj::XEditObj::AddRef()
{
    METHOD_PROLOGUE(CEditPrintObj, EditObj)
    return pThis->ExternalAddRef();
}

ULONG FAR EXPORT CEditPrintObj::XEditObj::Release()
{
    METHOD_PROLOGUE(CEditPrintObj, EditObj)
    return pThis->ExternalRelease();
}

HRESULT FAR EXPORT CEditPrintObj::XEditObj::QueryInterface(
    REFIID iid,
    void FAR* FAR* ppvObj)
{
    METHOD_PROLOGUE(CEditPrintObj, EditObj)
    return (HRESULT)pThis->ExternalQueryInterface(&iid, ppvObj);
}

void FAR EXPORT CEditPrintObj::XEditObj::EditObject()
{
    METHOD_PROLOGUE(CEditPrintObj, EditObj)
    // code to "Edit" the object, whatever that means...
}
```

A implementação para CEditPrintObj:: CPrintObj, seria semelhante às definições acima para CEditPrintObj:: CEditObj. Embora seja possível criar uma macro que pudesse ser usada para gerar essas funções automaticamente (mas antes no desenvolvimento de MFC/OLE, esse era o caso), torna-se difícil definir pontos de interrupção quando uma macro gera mais de uma linha de código. Por esse motivo, esse código é expandido manualmente.

Ao usar a implementação de estrutura de mapas de mensagem, há várias coisas que não eram necessárias para fazer isso:

- Implementar QueryInterface

- Implementar AddRef e Release

- Declare um desses métodos internos em ambas as interfaces

Além disso, a estrutura usa os mapas de mensagens internamente. Isso permite que você derive de uma classe de estrutura, digamos `COleServerDoc` , que já ofereça suporte a determinadas interfaces e forneça substituições ou adições às interfaces fornecidas pela estrutura. Você pode fazer isso porque a estrutura dá suporte total à herança de um mapa de interface de uma classe base. Essa é a razão pela qual BEGIN_INTERFACE_MAP leva como seu segundo parâmetro o nome da classe base.

> [!NOTE]
> Em geral, não é possível reutilizar a implementação das implementações internas do MFC das interfaces OLE apenas herdando a especialização inserida dessa interface da versão do MFC. Isso não é possível porque o uso da macro METHOD_PROLOGUE para obter acesso ao `CCmdTarget` objeto derivado contido implica um *deslocamento fixo* do objeto incorporado do `CCmdTarget` objeto derivado. Isso significa, por exemplo, que você não pode derivar um XMyAdviseSink incorporado da implementação do MFC no `COleClientItem::XAdviseSink` , porque XAdviseSink se baseia em um deslocamento específico da parte superior do `COleClientItem` objeto.

> [!NOTE]
> No entanto, é possível delegar para a implementação do MFC para todas as funções que você deseja que o comportamento padrão do MFC. Isso é feito na implementação do MFC de `IOleInPlaceFrame` (XOleInPlaceFrame) na `COleFrameHook` classe (ele delega para m_xOleInPlaceUIWindow para muitas funções). Esse design foi escolhido para reduzir o tamanho do tempo de execução de objetos que implementam muitas interfaces; Ele elimina a necessidade de um ponteiro de apoio (como o modo m_pParent foi usado na seção anterior).

### <a name="aggregation-and-interface-maps"></a>Agregação e mapas de interface

Além de oferecer suporte a objetos COM autônomos, o MFC também oferece suporte à agregação. A agregação em si é um tópico muito complexo para discutir aqui; consulte o tópico de [agregação](/windows/win32/com/aggregation) para obter mais informações sobre agregação. Essa observação simplesmente descreverá o suporte para agregação incorporada à estrutura e aos mapas de interface.

Há duas maneiras de usar a agregação: (1) usando um objeto COM que dá suporte à agregação e (2) implementando um objeto que pode ser agregado por outro. Esses recursos podem ser chamados de "usando um objeto agregado" e "tornando um objeto agregável". O MFC dá suporte a ambos.

### <a name="using-an-aggregate-object"></a>Usando um objeto de agregação

Para usar um objeto de agregação, precisa haver alguma maneira de vincular a agregação ao mecanismo de QueryInterface. Em outras palavras, o objeto de agregação deve se comportar como se fosse uma parte nativa do seu objeto. Então, como isso se vincula ao mecanismo de mapa de interface do MFC, além da macro INTERFACE_PART, em que um objeto aninhado é mapeado para um IID, você também pode declarar um objeto de agregação como parte de sua `CCmdTarget` classe derivada. Para fazer isso, a macro INTERFACE_AGGREGATE é usada. Isso permite que você especifique uma variável de membro (que deve ser um ponteiro para uma classe [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) ou derivada), que será integrada ao mecanismo de mapa de interface. Se o ponteiro não for nulo quando `CCmdTarget::ExternalQueryInterface` for chamado, a estrutura chamará automaticamente a função de membro [QueryInterface](/windows/win32/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) do objeto de agregação, se o `IID` solicitado não for um dos `IID` s nativos com suporte no `CCmdTarget` próprio objeto.

#### <a name="to-use-the-interface_aggregate-macro"></a>Para usar a macro INTERFACE_AGGREGATE

1. Declare uma variável de membro (um `IUnknown*` ) que conterá um ponteiro para o objeto de agregação.

2. Inclua uma macro INTERFACE_AGGREGATE em seu mapa de interface, que se refere à variável de membro por nome.

3. Em algum momento (geralmente durante `CCmdTarget::OnCreateAggregates` ), inicialize a variável de membro para algo diferente de NULL.

Por exemplo:

```cpp
class CAggrExample : public CCmdTarget
{
public:
    CAggrExample();

protected:
    LPUNKNOWN m_lpAggrInner;
    virtual BOOL OnCreateAggregates();

    DECLARE_INTERFACE_MAP()
    // "native" interface part macros may be used here
};

CAggrExample::CAggrExample()
{
    m_lpAggrInner = NULL;
}

BOOL CAggrExample::OnCreateAggregates()
{
    // wire up aggregate with correct controlling unknown
    m_lpAggrInner = CoCreateInstance(CLSID_Example,
        GetControllingUnknown(), CLSCTX_INPROC_SERVER,
        IID_IUnknown, (LPVOID*)&m_lpAggrInner);

    if (m_lpAggrInner == NULL)
        return FALSE;
    // optionally, create other aggregate objects here
    return TRUE;
}

BEGIN_INTERFACE_MAP(CAggrExample, CCmdTarget)
    // native "INTERFACE_PART" entries go here
    INTERFACE_AGGREGATE(CAggrExample, m_lpAggrInner)
END_INTERFACE_MAP()
```

A variável m_lpAggrInner é inicializada no construtor como NULL. A estrutura ignora uma variável de membro NULL na implementação padrão de [QueryInterface](/windows/win32/api/unknwn/nf-unknwn-iunknown-queryinterface(q)). `OnCreateAggregates`é um bom lugar para realmente criar seus objetos agregados. Você precisará chamá-lo explicitamente se estiver criando o objeto fora da implementação do MFC do `COleObjectFactory` . O motivo para a criação de agregações no `CCmdTarget::OnCreateAggregates` , bem como o uso de `CCmdTarget::GetControllingUnknown` será aparente quando a criação de objetos agregáveis for discutida.

Essa técnica fornecerá ao seu objeto todas as interfaces às quais o objeto de agregação dá suporte mais suas interfaces nativas. Se você quiser apenas um subconjunto das interfaces às quais a agregação dá suporte, você pode substituir `CCmdTarget::GetInterfaceHook` . Isso permite uma conexão de nível muito baixo, semelhante a [QueryInterface](/windows/win32/api/unknwn/nf-unknwn-iunknown-queryinterface(q)). Normalmente, você deseja todas as interfaces às quais a agregação dá suporte.

### <a name="making-an-object-implementation-aggregatable"></a>Tornando uma implementação de objeto agregável

Para que um objeto seja agregável, a implementação de [AddRef](/windows/win32/api/unknwn/nf-unknwn-iunknown-addref), [Release](/windows/win32/api/unknwn/nf-unknwn-iunknown-release)e [QueryInterface](/windows/win32/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) deve delegar a um "controle desconhecido". Em outras palavras, para que ele faça parte do objeto, ele deve delegar [AddRef](/windows/win32/api/unknwn/nf-unknwn-iunknown-addref), [Release](/windows/win32/api/unknwn/nf-unknwn-iunknown-release)e [QueryInterface](/windows/win32/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) para um objeto diferente, também derivado de [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown). Esse "controle desconhecido" é fornecido ao objeto quando ele é criado, ou seja, é fornecido para a implementação de `COleObjectFactory` . Implementar isso resulta em uma pequena quantidade de sobrecarga e, em alguns casos, não é desejável, portanto, o MFC torna isso opcional. Para permitir que um objeto seja agregável, você chama `CCmdTarget::EnableAggregation` a partir do construtor do objeto.

Se o objeto também usar agregações, você também deverá ter a certeza de passar o "controle desconhecido" correto para os objetos de agregação. Normalmente, esse ponteiro [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) é passado para o objeto quando a agregação é criada. Por exemplo, o parâmetro pUnkOuter é o "controle desconhecido" para objetos criados com o `CoCreateInstance` . O ponteiro "controlando desconhecido" correto pode ser recuperado chamando `CCmdTarget::GetControllingUnknown` . O valor retornado dessa função, no entanto, não é válido durante o construtor. Por esse motivo, é recomendável que você crie suas agregações somente em uma substituição de `CCmdTarget::OnCreateAggregates` , em que o valor de retorno de `GetControllingUnknown` é confiável, mesmo se criado da `COleObjectFactory` implementação.

Também é importante que o objeto manipule a contagem de referência correta ao adicionar ou liberar contagens de referência artificial. Para garantir que esse é o caso, sempre chame `ExternalAddRef` e `ExternalRelease` , em vez de `InternalRelease` e `InternalAddRef` . É raro chamar `InternalRelease` ou `InternalAddRef` em uma classe que dá suporte à agregação.

## <a name="reference-material"></a>Material de referência

O uso avançado de OLE, como a definição de suas próprias interfaces ou a substituição da implementação da estrutura das interfaces OLE, requer o uso do mecanismo de mapa de interface subjacente.

Esta seção discute cada macro e as APIs que são usadas para implementar esses recursos avançados.

### <a name="ccmdtargetenableaggregation--function-description"></a>CCmdTarget:: EnableAggregation – descrição da função

```cpp
void EnableAggregation();
```

#### <a name="remarks"></a>Comentários

Chame essa função no construtor da classe derivada se desejar dar suporte à agregação OLE para objetos desse tipo. Isso prepara uma implementação IUnknown especial que é necessária para objetos agregáveis.

### <a name="ccmdtargetexternalqueryinterface--function-description"></a>CCmdTarget:: ExternalQueryInterface – descrição da função

```cpp
DWORD ExternalQueryInterface(
    const void FAR* lpIID,
    LPVOIDFAR* ppvObj
);
```

#### <a name="parameters"></a>parâmetros

*lpIID*<br/>
Um ponteiro distante para um IID (o primeiro argumento para QueryInterface)

*ppvObj*<br/>
Um ponteiro para um IUnknown * (segundo argumento para QueryInterface)

#### <a name="remarks"></a>Comentários

Chame essa função em sua implementação de IUnknown para cada interface implementada pela sua classe. Essa função fornece a implementação controlada por dados padrão de QueryInterface com base no mapa de interface do seu objeto. É necessário converter o valor de retorno em um HRESULT. Se o objeto for agregado, essa função chamará o "controle de IUnknown" em vez de usar o mapa de interface local.

### <a name="ccmdtargetexternaladdref--function-description"></a>CCmdTarget:: ExternalAddRef – Descrição da função

```cpp
DWORD ExternalAddRef();
```

#### <a name="remarks"></a>Comentários

Chame essa função em sua implementação de IUnknown:: AddRef para cada interface implementada pela sua classe. O valor de retorno é a nova contagem de referência no objeto CCmdTarget. Se o objeto for agregado, essa função chamará o "controle de IUnknown" em vez de manipular a contagem de referências local.

### <a name="ccmdtargetexternalrelease--function-description"></a>CCmdTarget:: ExternalRelease – descrição da função

```cpp
DWORD ExternalRelease();
```

#### <a name="remarks"></a>Comentários

Chame essa função em sua implementação de IUnknown:: Release para cada interface implementada pela sua classe. O valor de retorno indica a nova contagem de referência no objeto. Se o objeto for agregado, essa função chamará o "controle de IUnknown" em vez de manipular a contagem de referências local.

### <a name="declare_interface_map--macro-description"></a>DECLARE_INTERFACE_MAP — descrição da macro

```cpp
DECLARE_INTERFACE_MAP
```

#### <a name="remarks"></a>Comentários

Use essa macro em qualquer classe derivada de `CCmdTarget` que terá um mapa de interface. Usado quase da mesma maneira que DECLARE_MESSAGE_MAP. Essa invocação de macro deve ser colocada na definição de classe, geralmente em um cabeçalho (. H). Uma classe com DECLARE_INTERFACE_MAP deve definir o mapa de interface no arquivo de implementação (. CPP) com as macros BEGIN_INTERFACE_MAP e END_INTERFACE_MAP.

### <a name="begin_interface_part-and-end_interface_part--macro-descriptions"></a>BEGIN_INTERFACE_PART e END_INTERFACE_PART — descrições de macro

```cpp
BEGIN_INTERFACE_PART(localClass, iface);
END_INTERFACE_PART(localClass)
```

#### <a name="parameters"></a>parâmetros

*localClass*<br/>
O nome da classe que implementa a interface

*iface*<br/>
O nome da interface que essa classe implementa

#### <a name="remarks"></a>Comentários

Para cada interface que sua classe implementará, você precisará ter um BEGIN_INTERFACE_PART e END_INTERFACE_PART par. Essas macros definem uma classe local derivada da interface OLE que você define, bem como uma variável de membro inserida dessa classe. Os membros [AddRef](/windows/win32/api/unknwn/nf-unknwn-iunknown-addref), [Release](/windows/win32/api/unknwn/nf-unknwn-iunknown-release)e [QueryInterface](/windows/win32/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) são declarados automaticamente. Você deve incluir as declarações para as outras funções de membro que fazem parte da interface que está sendo implementada (essas declarações são colocadas entre as macros BEGIN_INTERFACE_PART e END_INTERFACE_PART).

O argumento *iface* é a interface OLE que você deseja implementar, como `IAdviseSink` ou `IPersistStorage` (ou sua própria interface personalizada).

O argumento *localClass* é o nome da classe local que será definida. Um ' X ' será automaticamente anexado ao nome. Essa convenção de nomenclatura é usada para evitar colisões com classes globais de mesmo nome. Além disso, o nome do membro inserido, o mesmo que o nome *localClass* , exceto que é prefixado por ' m_x '.

Por exemplo:

```cpp
BEGIN_INTERFACE_PART(MyAdviseSink, IAdviseSink)
    STDMETHOD_(void, OnDataChange)(LPFORMATETC, LPSTGMEDIUM);
    STDMETHOD_(void, OnViewChange)(DWORD, LONG);
    STDMETHOD_(void, OnRename)(LPMONIKER);
    STDMETHOD_(void, OnSave)();
    STDMETHOD_(void, OnClose)();
END_INTERFACE_PART(MyAdviseSink)
```

definiria uma classe local chamada XMyAdviseSink derivada de IAdviseSink e um membro da classe na qual ela foi declarada chamada m_xMyAdviseSink. Observação:

> [!NOTE]
> As linhas que começam com `STDMETHOD` _ são basicamente copiadas de OLE2. H e modificou ligeiramente. Copiando-os de OLE2. A H pode reduzir os erros que são difíceis de resolver.

### <a name="begin_interface_map-and-end_interface_map--macro-descriptions"></a>BEGIN_INTERFACE_MAP e END_INTERFACE_MAP — descrições de macro

```cpp
BEGIN_INTERFACE_MAP(theClass, baseClass)
END_INTERFACE_MAP
```

#### <a name="parameters"></a>parâmetros

*Classe*<br/>
A classe na qual o mapa de interface deve ser definido

*baseClass*<br/>
A classe da qual deriva a *classe* .

#### <a name="remarks"></a>Comentários

As macros BEGIN_INTERFACE_MAP e END_INTERFACE_MAP são usadas no arquivo de implementação para realmente definir o mapa de interface. Para cada interface implementada, há uma ou mais invocações de macro INTERFACE_PART. Para cada agregação que a classe usa, há uma chamada de macro INTERFACE_AGGREGATE.

### <a name="interface_part--macro-description"></a>INTERFACE_PART — descrição da macro

```cpp
INTERFACE_PART(theClass, iid, localClass)
```

#### <a name="parameters"></a>parâmetros

*Classe*<br/>
O nome da classe que contém o mapa de interface.

*IID*<br/>
O `IID` que deve ser mapeado para a classe inserida.

*localClass*<br/>
O nome da classe local (menos o ' X ').

#### <a name="remarks"></a>Comentários

Essa macro é usada entre a macro BEGIN_INTERFACE_MAP e a macro END_INTERFACE_MAP para cada interface à qual seu objeto dará suporte. Ele permite mapear um IID para um membro da classe indicada pela *classe* e *localClass*. O ' m_x ' será adicionado ao *localClass* automaticamente. Observe que mais de um `IID` pode estar associado a um único membro. Isso é muito útil quando você está implementando apenas uma interface "mais derivada" e deseja fornecer todas as interfaces intermediárias também. Um bom exemplo disso é a `IOleInPlaceFrameWindow` interface. Sua hierarquia é parecida com esta:

```Hierarchy
IUnknown
    IOleWindow
        IOleUIWindow
            IOleInPlaceFrameWindow
```

Se um objeto for implementado `IOleInPlaceFrameWindow` , um cliente poderá `QueryInterface` em qualquer uma dessas interfaces: `IOleUIWindow` , `IOleWindow` ou [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown), além da interface "mais derivada" `IOleInPlaceFrameWindow` (aquela que você está implementando de fato). Para lidar com isso, você pode usar mais de uma macro INTERFACE_PART para mapear cada interface base para a `IOleInPlaceFrameWindow` interface:

no arquivo de definição de classe:

```cpp
BEGIN_INTERFACE_PART(CMyFrameWindow, IOleInPlaceFrameWindow)
```

no arquivo de implementação de classe:

```cpp
BEGIN_INTERFACE_MAP(CMyWnd, CFrameWnd)
    INTERFACE_PART(CMyWnd, IID_IOleWindow, MyFrameWindow)
    INTERFACE_PART(CMyWnd, IID_IOleUIWindow, MyFrameWindow)
    INTERFACE_PART(CMyWnd, IID_IOleInPlaceFrameWindow, MyFrameWindow)
END_INTERFACE_MAP
```

A estrutura cuida de IUnknown porque é sempre necessária.

### <a name="interface_part--macro-description"></a>INTERFACE_PART — descrição da macro

```cpp
INTERFACE_AGGREGATE(theClass, theAggr)
```

#### <a name="parameters"></a>parâmetros

*Classe*<br/>
O nome da classe que contém o mapa de interface,

*theAggr*<br/>
O nome da variável de membro a ser agregada.

#### <a name="remarks"></a>Comentários

Essa macro é usada para informar à estrutura que a classe está usando um objeto de agregação. Ele deve aparecer entre as macros BEGIN_INTERFACE_PART e END_INTERFACE_PART. Um objeto de agregação é um objeto separado, derivado de [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown). Usando uma agregação e a macro INTERFACE_AGGREGATE, você pode fazer com que todas as interfaces às quais a agregação dá suporte pareçam diretamente compatíveis com o objeto. O argumento *theAggr* é simplesmente o nome de uma variável de membro da sua classe, que é derivada de [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) (direta ou indiretamente). Todas as macros INTERFACE_AGGREGATE devem seguir as macros INTERFACE_PART quando colocadas em um mapa de interface.

## <a name="see-also"></a>Confira também

[Notas técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Notas técnicas por categoria](../mfc/technical-notes-by-category.md)
