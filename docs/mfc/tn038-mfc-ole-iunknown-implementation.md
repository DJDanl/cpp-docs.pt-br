---
title: 'TN038: Implementação de IUnknown MFC-OLE'
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
ms.openlocfilehash: a366d200c272570b4806a8642f287a7ef69b430e
ms.sourcegitcommit: 934cb53fa4cb59fea611bfeb9db110d8d6f7d165
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/14/2019
ms.locfileid: "65611318"
---
# <a name="tn038-mfcole-iunknown-implementation"></a>TN038: Implementação de IUnknown MFC/OLE

> [!NOTE]
> A nota técnica a seguir não foi atualizada desde que foi incluído pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação online.

No coração do OLE 2 é o "OLE Component Object Model", ou COM. COM define um padrão para os objetos de cooperação como se comunicar entre si. Isso inclui os detalhes dos quais um "objeto" se parece com, incluindo como os métodos são despachados em um objeto. COM também define uma classe base, da qual todas as classes de compatível COM são derivadas. Essa classe base é [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown). Embora o [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface é conhecido como uma classe do C++, COM não é específico para qualquer linguagem — pode ser implementado em C, PASCAL ou qualquer outra linguagem que pode dar suporte o layout binário de um objeto COM.

OLE refere-se a todas as classes derivadas [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) como "interfaces." Essa é uma distinção importante, desde uma "interface", como [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) não implica nenhuma implementação. Ele simplesmente define o protocolo pelo qual objetos se comunicam, não as especificidades do que essas implementações fazem. Isso é razoável para um sistema que permite a máxima flexibilidade. É do MFC para implementar um comportamento padrão para programas MFC/C++.

Para entender a implementação do MFC de [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) você deve primeiro compreender o que é essa interface. Uma versão simplificada [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) está definida abaixo:

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
> Detalha determinada convenção de chamada, como `__stdcall` foram deixados de fora para esta ilustração.

O [AddRef](/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) e [versão](/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) funções de membro de controlam o gerenciamento de memória do objeto. COM usa um esquema de contagem de referência para manter o controle de objetos. Um objeto nunca é referenciado diretamente como você faria em C++. Em vez disso, os objetos COM são sempre referenciados por meio de um ponteiro. Para liberar o objeto quando o proprietário é feito usando-o, o objeto [Release](/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) membro é chamado (em vez de usar o operador delete, como seria feito para um objeto de C++ tradicional). A mecanismo de contagem de referência permite que várias referências a um único objeto a serem gerenciados. Uma implementação de [AddRef](/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) e [versão](/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) mantém uma contagem de referência no objeto — o objeto não é excluído até que sua contagem de referência chega a zero.

[AddRef](/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) e [versão](/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) são relativamente simples de um ponto de vista de implementação. Aqui está uma implementação trivial:

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

O [QueryInterface](/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q_)) função de membro é um pouco mais interessante. Não é muito interessante ter um objeto cujas funções membro são [AddRef](/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) e [Release](/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) — seria ótimo dizer o objeto para fazer mais coisas que [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) fornece. É aí que [QueryInterface](/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q_)) é útil. Ele permite que você obtenha uma "interface" diferente no mesmo objeto. Essas interfaces geralmente são derivadas de [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) e adicionar funcionalidade adicional, adicionando novas funções de membro. Interfaces COM nunca têm variáveis de membros declaradas na interface e todas as funções membro são declaradas como virtuais puras. Por exemplo,

```cpp
class IPrintInterface : public IUnknown
{
public:
    virtual void PrintObject() = 0;
};
```

Para obter um IPrintInterface se você tiver apenas um [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown), chame [QueryInterface](/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q_)) usando o `IID` do `IPrintInterface`. Um `IID` é um número de 128 bits que identifica exclusivamente a interface. Há um `IID` para cada interface que você ou o OLE define. Se *pUnk* é um ponteiro para um [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) do objeto, o código para recuperar um IPrintInterface dele pode ser:

```cpp
IPrintInterface* pPrint = NULL;
if (pUnk->QueryInterface(IID_IPrintInterface, (void**)&pPrint) == NOERROR)
{
    pPrint->PrintObject();
    pPrint->Release();
    // release pointer obtained via QueryInterface
}
```

Isso é parece bastante fácil, mas como você implementaria um objeto que oferece suporte a IPrintInterface e [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface nesse caso, é simple, pois o IPrintInterface seja diretamente derivado de [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) — implementando IPrintInterface, [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) terá suporte automaticamente. Por exemplo:

```cpp
class CPrintObj : public CPrintInterface
{
    virtual HRESULT QueryInterface(REFIID iid, void** ppvObj);
    virtual ULONG AddRef();
    virtual ULONG Release();
    virtual void PrintObject();
};
```

As implementações de [AddRef](/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) e [versão](/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) seria exatamente as mesmas que aquelas implementadas acima. `CPrintObj::QueryInterface` seria algo parecido com isto:

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

Como você pode ver, se o identificador de interface (IID) for reconhecido, um ponteiro é retornado ao objeto; Caso contrário, ocorrerá um erro. Observe também que bem-sucedida [QueryInterface](/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q_)) resulta em um implícitas [AddRef](/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref). É claro, você também precisaria implementar ceditobj:: Print. Isso é simples porque o IPrintInterface foi derivado diretamente do [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface. No entanto, se você quisesse dar suporte a duas interfaces diferentes, ambas derivadas [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown), considere o seguinte:

```cpp
class IEditInterface : public IUnkown
{
public:
    virtual void EditObject() = 0;
};
```

Embora haja um número de diferentes maneiras de implementar uma classe que suporta IEditInterface e IPrintInterface, incluindo o uso de C++ herança múltipla, essa observação se concentrará no uso de classes aninhadas para implementar essa funcionalidade.

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

A implementação completa está incluída abaixo:

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

Observe que a maioria dos [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) implementação é colocada na classe CEditPrintObj em vez de duplicar o código em Ceditprintobj e ceditprintobj::. Isso reduz a quantidade de código e evita bugs. O ponto principal aqui é que da interface IUnknown é possível chamar [QueryInterface](/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q_)) para recuperar qualquer interface o objeto possa ter suporte e de cada uma dessas interfaces, é possível fazer o mesmo. Isso significa que todos os [QueryInterface](/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q_)) funções disponíveis de cada interface devem se comportar exatamente da mesma maneira. Para esses objetos inseridos chamem a implementação no "objeto externo", um ponteiro de retorno é usado (m_pParent). O ponteiro m_pParent é inicializado durante o construtor CEditPrintObj. Em seguida, você poderia implementar PrintObject e Ceditprintobj também. Um pouco de código foi adicionado ao adicionar um recurso — a capacidade de editar o objeto. Felizmente, é muito incomum para interfaces ter apenas uma única função de membro (embora isso aconteça) e, nesse caso, EditObject e PrintObject geralmente seriam combinados em uma única interface.

Isso é muita explicação e muito código para um cenário tão simples. As classes do MFC/OLE fornecem uma alternativa mais simples. A implementação do MFC usa uma técnica semelhante à forma como as mensagens do Windows são encapsuladas com mapas de mensagem. Esse recurso é chamado *mapas de Interface* e é abordado na próxima seção.

## <a name="mfc-interface-maps"></a>Mapas de Interface do MFC

MFC/OLE inclui uma implementação de "Mapas de Interface" semelhante do MFC "Mapas de mensagem" e "Mapas de expedição" em conceito e em execução. Os principais recursos do mapas de Interface MFC são da seguinte maneira:

- Uma implementação padrão de [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown), compilada no `CCmdTarget` classe.

- Manutenção da contagem de referência, modificada por [AddRef](/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) e [versão](/windows/desktop/api/unknwn/nf-unknwn-iunknown-release)

- Implementação de orientada a dados [QueryInterface](/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q_))

Além disso, os mapas de interface suportam os seguintes recursos avançados:

- Suporte para a criação de objetos COM agregável

- Suporte para usar objetos agregados na implementação de um objeto COM

- A implementação é extensível e pode ser ligada

Para obter mais informações sobre agregação, consulte o [agregação](/windows/desktop/com/aggregation) tópico.

Suporte de mapa de interface do MFC está enraizado no `CCmdTarget` classe. `CCmdTarget` "*tem um*" fazer referência a contagem, bem como todas as funções de membro associadas com o [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) implementação (por exemplo é a contagem de referência em `CCmdTarget`). Para criar uma classe que suporta OLE COM, você deriva uma classe de `CCmdTarget` e usa várias macros, bem como funções de membro de `CCmdTarget` para implementar as interfaces desejadas. A implementação do MFC usa classes aninhadas para definir cada implementação da interface muito semelhante ao exemplo acima. Isso é facilitado com uma implementação padrão de IUnknown, bem como um número de macros que eliminam parte do código repetitivo.

## <a name="interface-map-basics"></a>Noções básicas de mapa de interface

### <a name="to-implement-a-class-using-mfcs-interface-maps"></a>Para implementar uma classe usando a interface do MFC mapeia

1. Derive uma classe direta ou indiretamente de `CCmdTarget`.

2. Use o `DECLARE_INTERFACE_MAP` função na definição de classe derivada.

3. Para cada interface que você deseja dar suporte, use as macros BEGIN_INTERFACE_PART e END_INTERFACE_PART na definição de classe.

4. No arquivo de implementação, use as macros BEGIN_INTERFACE_MAP e END_INTERFACE_MAP para definir o mapa da interface da classe.

5. Para cada IID suportado, use a macro INTERFACE_PART entre as macros BEGIN_INTERFACE_MAP e END_INTERFACE_MAP para mapear o IID a uma "parte" da sua classe específica.

6. Implemente cada uma das classes aninhadas que representam as interfaces que você oferece suporte.

7. Use a macro METHOD_PROLOGUE para acessar o pai, `CCmdTarget`-objeto derivado.

8. [AddRef](/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref), [Release](/windows/desktop/api/unknwn/nf-unknwn-iunknown-release), e [QueryInterface](/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q_)) pode delegar para o `CCmdTarget` implementação dessas funções (`ExternalAddRef`, `ExternalRelease`, e `ExternalQueryInterface`).

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

A declaração acima cria uma classe derivada de `CCmdTarget`. A macro DECLARE_INTERFACE_MAP informa a estrutura que essa classe terá um mapa de interface personalizada. Além disso, as macros BEGIN_INTERFACE_PART e END_INTERFACE_PART definem classes aninhadas, nesse caso, com nomes CEditObj e CPrintObj (o X é usado para diferenciar as classes aninhadas de classes globais que começam com "C" e a interface de classes que somente Inicie com "I"). Dois membros aninhados dessas classes são criados: m_CEditObj e m_CPrintObj, respectivamente. As macros declaram automaticamente a [AddRef](/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref), [versão](/windows/desktop/api/unknwn/nf-unknwn-iunknown-release), e [QueryInterface](/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q_)) funções; portanto, você declara somente as funções específicas dessa interface: EditObject e PrintObject (a macro OLE STDMETHOD é usado para que **stdcall** e palavras-chave virtuais sejam fornecidas conforme apropriado para a plataforma de destino).

Para implementar o mapa de interface para esta classe:

```cpp
BEGIN_INTERFACE_MAP(CPrintEditObj, CCmdTarget)
    INTERFACE_PART(CPrintEditObj, IID_IPrintInterface, PrintObj)
    INTERFACE_PART(CPrintEditObj, IID_IEditInterface, EditObj)
END_INTERFACE_MAP()
```

Isso conecta o IID IID_IPrintInterface com m_CPrintObj e IID_IEditInterface com m_CEditObj respectivamente. O `CCmdTarget` implementací [QueryInterface](/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q_)) (`CCmdTarget::ExternalQueryInterface`) usa esse mapa para retornar ponteiros para m_CPrintObj e m_ceditobj quando for solicitado. Não é necessário incluir uma entrada para `IID_IUnknown`; a estrutura usará a primeira interface no mapa (neste caso, m_CPrintObj) quando `IID_IUnknown` é solicitada.

Mesmo que a macro BEGIN_INTERFACE_PART declarado automaticamente a [AddRef](/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref), [Release](/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) e [QueryInterface](/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q_)) funções para você, você ainda precisará implementá-los:

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

A implementação para ceditprintobj:: cprintobj será semelhante às definições acima para Ceditprintobj. Embora seria possível criar uma macro que pode ser usada para gerar automaticamente essas funções (mas mais cedo no desenvolvimento de MFC/OLE, esse era o caso), fica difícil definir pontos de interrupção quando uma macro gerencia mais de uma linha de código. Por esse motivo, esse código é expandido manualmente.

Usando a implementação de estrutura de mapas de mensagem, há várias coisas que não eram necessárias fazer:

- Implementar QueryInterface

- Implemente AddRef e versão

- Declarar qualquer um desses métodos internos em ambas as interfaces

Além disso, a estrutura usa internamente mapas de mensagem. Isso permite que você derive de uma classe do framework, digamos `COleServerDoc`, já que oferece suporte a determinadas interfaces e forneça substituições ou adições às interfaces fornecidas pela estrutura. Você pode fazer isso porque a estrutura é totalmente compatível com um mapa de interface de herança de uma classe base. Que é o motivo por que BEGIN_INTERFACE_MAP utiliza como seu segundo parâmetro o nome da classe base.

> [!NOTE]
> Geralmente, não é possível reutilizar a implementação das implementações internas do MFC das interfaces OLE simplesmente herdando a especialização inserida da interface da versão do MFC. Isso não é possível porque o uso da macro METHOD_PROLOGUE para obter acesso a que contém `CCmdTarget`-objeto derivado implica uma *deslocamento fixo* do objeto inserido do `CCmdTarget`-objeto derivado. Isso significa que, por exemplo, você não pode derivar um XMyAdviseSink inserido da implementação MFC em `COleClientItem::XAdviseSink`, porque XAdviseSink depende de estar em um deslocamento específico da parte superior do `COleClientItem` objeto.

> [!NOTE]
> No entanto, você pode, delegar para a implementação do MFC para todas as funções que você deseja que o comportamento padrão MFC. Isso é feito na implementação do MFC `IOleInPlaceFrame` (XOleInPlaceFrame) no `COleFrameHook` classe (ela delega ao m_xOleInPlaceUIWindow para muitas funções). Este projeto foi escolhido para reduzir o tamanho de tempo de execução de objetos que implementam muitas interfaces; Ele elimina a necessidade de um ponteiro de retorno (como a maneira que m_pParent foi usado na seção anterior).

### <a name="aggregation-and-interface-maps"></a>Mapas de Interface e de agregação

Além de dar suporte a objetos COM autônomos, o MFC também oferece suporte à agregação. Agregação em si é um tópico muito complexo para discutir aqui; Consulte a [agregação](/windows/desktop/com/aggregation) tópico para obter mais informações sobre a agregação. Essa observação simplesmente descreverá o suporte para a agregação compilada nos mapas de estrutura e a interface.

Há duas maneiras de usar a agregação: (1) usando um objeto COM que dá suporte à agregação e (2) implementando um objeto que pode ser agregado por outro. Esses recursos podem ser chamados de "usando um objeto agregado" e "tornando um objeto agregável". MFC dá suporte a ambos.

### <a name="using-an-aggregate-object"></a>Usando um objeto agregado

Para usar um objeto agregado, haverá necessidade de alguma forma para vincular a agregação em mecanismo de QueryInterface. Em outras palavras, o objeto agregado deve se comportar como se fosse uma parte nativa de seu objeto. Então, como faz a ligação no mecanismo de mapa de interface do MFC, além de macro INTERFACE_PART, onde um objeto aninhado é mapeado para uma IID, você também pode declarar um objeto agregado como parte de seu `CCmdTarget` classe derivada. Para fazer isso, a macro INTERFACE_AGGREGATE é usada. Isso permite que você especifique uma variável de membro (que deve ser um ponteiro para um [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) ou classe derivada), que deve ser integrada ao mecanismo de mapa de interface. Se o ponteiro não for nulo quando `CCmdTarget::ExternalQueryInterface` é chamado, a estrutura chamará automaticamente o objeto agregado [QueryInterface](/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q_)) função de membro, se o `IID` solicitado não é um dos nativo `IID`s suporte a `CCmdTarget` objeto propriamente dito.

#### <a name="to-use-the-interfaceaggregate-macro"></a>Para usar a macro INTERFACE_AGGREGATE

1. Declare uma variável de membro (um `IUnknown*`) que conterá um ponteiro para o objeto agregado.

2. Inclua uma macro INTERFACE_AGGREGATE no mapa de interface, que se refere à variável de membro por nome.

3. Em algum momento (geralmente durante `CCmdTarget::OnCreateAggregates`), inicialize a variável de membro para algo diferente de NULL.

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

A variável m_lpAggrInner é inicializada no construtor para NULL. A estrutura ignora uma variável de membro NULL na implementação padrão de [QueryInterface](/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q_)). `OnCreateAggregates` é um bom lugar para criar realmente seus objetos agregados. Você terá que chamar explicitamente se você estiver criando o objeto fora de implementação MFC de `COleObjectFactory`. O motivo para criar agregações em `CCmdTarget::OnCreateAggregates` , bem como o uso de `CCmdTarget::GetControllingUnknown` se tornará aparente quando a criação de objetos agregáveis são discutidas.

Essa técnica dará ao objeto todas as interfaces que o objeto agregado suporta além de suas interfaces nativas. Se você quiser apenas um subconjunto das interfaces que dá suporte a agregação, você pode substituir `CCmdTarget::GetInterfaceHook`. Isso lhe permite hookability de nível muito baixo, semelhante à [QueryInterface](/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q_)). Geralmente, você deseja que todas as interfaces que dá suporte à agregação.

### <a name="making-an-object-implementation-aggregatable"></a>Tornando uma implementação de objeto agregável

Para um objeto seja agregável, a implementação de [AddRef](/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref), [Release](/windows/desktop/api/unknwn/nf-unknwn-iunknown-release), e [QueryInterface](/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q_)) deverá delegar a um "controle desconhecido". Em outras palavras, para que ele seja parte do objeto, ele deverá delegar [AddRef](/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref), [Release](/windows/desktop/api/unknwn/nf-unknwn-iunknown-release), e [QueryInterface](/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q_)) para um objeto diferente, também derivado de [ IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown). Esse "controle desconhecido" é fornecido para o objeto quando ele é criado, ou seja, ele é fornecido para a implementação de `COleObjectFactory`. Implementar isso representa uma pequena quantidade de sobrecarga e em alguns casos não for desejável, portanto, o MFC torna isso opcional. Para ativar um objeto seja agregável, chame `CCmdTarget::EnableAggregation` do construtor do objeto.

Se o objeto também usar agregados, você também deve ser transmita correto "controle desconhecido" para os objetos agregados. Normalmente, isso [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) ponteiro é passado para o objeto quando a agregação é criada. Por exemplo, o parâmetro pUnkOuter é o "controle desconhecido" para objetos criados com `CoCreateInstance`. O ponteiro do "controle desconhecido" correto pode ser recuperado chamando `CCmdTarget::GetControllingUnknown`. O valor retornado dessa função, no entanto, não é válido durante o construtor. Por esse motivo, é recomendável que você crie seus agregados somente em uma substituição de `CCmdTarget::OnCreateAggregates`, em que o valor retornado de `GetControllingUnknown` é confiável, mesmo se criado a partir de `COleObjectFactory` implementação.

Também é importante que o objeto manipule a contagem de referência correta ao adicionar ou liberar contagens de referência artificiais. Para garantir que esse é o caso, sempre chame `ExternalAddRef` e `ExternalRelease` em vez de `InternalRelease` e `InternalAddRef`. É raro para chamar `InternalRelease` ou `InternalAddRef` em uma classe que dá suporte à agregação.

## <a name="reference-material"></a>Material de referência

Uso avançado do OLE, como definir suas próprias interfaces ou substituição da implementação das interfaces OLE requer o uso do mecanismo de mapa de interface subjacente.

Esta seção aborda cada macro e as APIs que são usadas para implementar esses recursos avançados.

### <a name="ccmdtargetenableaggregation--function-description"></a>CCmdTarget:: Enableaggregation — Descrição da função

```cpp
void EnableAggregation();
```

#### <a name="remarks"></a>Comentários

Chame essa função no construtor da classe derivada se você deseja dar suporte a agregação OLE para objetos desse tipo. Isso prepara uma implementação IUnknown especial que é necessária para objetos agregáveis.

### <a name="ccmdtargetexternalqueryinterface--function-description"></a>CCmdTarget:: Externalqueryinterface — Descrição da função

```cpp
DWORD ExternalQueryInterface(
    const void FAR* lpIID,
    LPVOIDFAR* ppvObj
);
```

#### <a name="parameters"></a>Parâmetros

*lpIID*<br/>
Um ponteiro distante a um IID (o primeiro argumento para QueryInterface)

*ppvObj*<br/>
Um ponteiro para um IUnknown * (o segundo argumento para QueryInterface)

#### <a name="remarks"></a>Comentários

Chame essa função em sua implementação de IUnknown para cada interface de sua classe implementa. Essa função fornece a implementação de orientado a dados padrão de QueryInterface com base no mapa da interface do objeto. É necessário converter o valor de retorno para um HRESULT. Se o objeto for agregado, essa função chamará o "controle IUnknown" em vez de usar o mapa de interface local.

### <a name="ccmdtargetexternaladdref--function-description"></a>CCmdTarget:: Externaladdref — Descrição da função

```cpp
DWORD ExternalAddRef();
```

#### <a name="remarks"></a>Comentários

Chame essa função em sua implementação de IUnknown:: AddRef para cada interface de sua classe implementa. O valor de retorno é a nova contagem de referência no objeto CCmdTarget. Se o objeto for agregado, essa função chamará o "controle IUnknown" em vez de manipular a contagem de referência local.

### <a name="ccmdtargetexternalrelease--function-description"></a>CCmdTarget:: Externalrelease — Descrição da função

```cpp
DWORD ExternalRelease();
```

#### <a name="remarks"></a>Comentários

Chame essa função em sua implementação de IUnknown:: Release para cada interface de sua classe implementa. O valor retornado indica a nova contagem de referência no objeto. Se o objeto for agregado, essa função chamará o "controle IUnknown" em vez de manipular a contagem de referência local.

### <a name="declareinterfacemap--macro-description"></a>DECLARE_INTERFACE_MAP — Descrição da Macro

```cpp
DECLARE_INTERFACE_MAP
```

#### <a name="remarks"></a>Comentários

Use este macro em qualquer classe derivada de `CCmdTarget` que terá um mapa de interface. Usado em grande parte da mesma maneira que DECLARE_MESSAGE_MAP. Essa invocação de macro deve ser colocada na definição de classe, geralmente em um cabeçalho (. H) arquivo do. Uma classe com DECLARE_INTERFACE_MAP deve definir o mapa de interface no arquivo de implementação (. CPP) com as macros BEGIN_INTERFACE_MAP e END_INTERFACE_MAP.

### <a name="begininterfacepart-and-endinterfacepart--macro-descriptions"></a>BEGIN_INTERFACE_PART e END_INTERFACE_PART — descrições Macro

```cpp
BEGIN_INTERFACE_PART(localClass, iface);
END_INTERFACE_PART(localClass)
```

#### <a name="parameters"></a>Parâmetros

*localClass*<br/>
O nome da classe que implementa a interface

*iface*<br/>
O nome da interface que essa classe implementa

#### <a name="remarks"></a>Comentários

Para cada interface que sua classe implementará, você precisa ter um par BEGIN_INTERFACE_PART e END_INTERFACE_PART. Essas macros definem uma classe local derivada da interface OLE que você define, bem como uma variável de membro inserida dessa classe. O [AddRef](/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref), [Release](/windows/desktop/api/unknwn/nf-unknwn-iunknown-release), e [QueryInterface](/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q_)) membros são declarados automaticamente. Você deve incluir as declarações para as outras funções de membro que fazem parte da interface que está sendo implementada (as declarações são colocadas entre as macros BEGIN_INTERFACE_PART e END_INTERFACE_PART).

O *iface* argumento é a interface OLE que você deseja implementar, tais como `IAdviseSink`, ou `IPersistStorage` (ou sua própria interface personalizada).

O *localClass* argumento é o nome da classe local que será definida. Um ' X' será anexado automaticamente ao nome. Esta convenção de nomenclatura é usada para evitar conflitos com classes globais do mesmo nome. Além disso, o nome do membro inserido, igual a *localClass* nome, exceto que ele é pelo prefixo 'm_x'.

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

definiria uma classe local chamada XMyAdviseSink derivado de IAdviseSink, e chamado de um membro da classe na qual ele é declarado m_xmyadvisesink. Note:

> [!NOTE]
> As linhas que começam com `STDMETHOD`_ são essencialmente copiadas do OLE2. H e ligeiramente modificados. Copiá-los de OLE2. H pode reduzir erros difíceis de resolver.

### <a name="begininterfacemap-and-endinterfacemap--macro-descriptions"></a>BEGIN_INTERFACE_MAP e END_INTERFACE_MAP — descrições Macro

```cpp
BEGIN_INTERFACE_MAP(theClass, baseClass)
END_INTERFACE_MAP
```

#### <a name="parameters"></a>Parâmetros

*theClass*<br/>
A classe na qual o mapa de interface deve ser definido

*baseClass*<br/>
A classe da qual *theClass* deriva.

#### <a name="remarks"></a>Comentários

As macros BEGIN_INTERFACE_MAP e END_INTERFACE_MAP são usadas no arquivo de implementação para definir o mapa de interface. Para cada interface implementada, há uma ou mais chamadas de macro INTERFACE_PART. Para cada agregação que usa a classe, há uma invocação de macro INTERFACE_AGGREGATE.

### <a name="interfacepart--macro-description"></a>INTERFACE_PART — Descrição da Macro

```cpp
INTERFACE_PART(theClass, iid, localClass)
```

#### <a name="parameters"></a>Parâmetros

*theClass*<br/>
O nome da classe que contém o mapa de interface.

*iid*<br/>
O `IID` que deve ser mapeado para a classe inserida.

*localClass*<br/>
O nome da classe local (menos 'X').

#### <a name="remarks"></a>Comentários

Essa macro é usada entre a macro BEGIN_INTERFACE_MAP e a macro END_INTERFACE_MAP para cada interface que o objeto dará suporte. Ele permite que você mapeie uma IID para um membro da classe indicada por *theClass* e *localClass*. O 'm_x' será adicionado para o *localClass* automaticamente. Observe que mais de uma `IID` podem estar associados um único membro. Isso é muito útil quando você estiver implementando apenas uma interface "mais derivada" e quiser fornecer todas as interfaces intermediárias. Um bom exemplo disso é o `IOleInPlaceFrameWindow` interface. Sua hierarquia tem esta aparência:

```Hierarchy
IUnknown
    IOleWindow
        IOleUIWindow
            IOleInPlaceFrameWindow
```

Se um objeto que implementa `IOleInPlaceFrameWindow`, um cliente poderá `QueryInterface` em qualquer uma dessas interfaces: `IOleUIWindow`, `IOleWindow`, ou [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown), além da interface "mais derivada" `IOleInPlaceFrameWindow` (aquele que está realmente Implementando). Para lidar com isso, você pode usar mais de uma macro INTERFACE_PART para mapear cada interface base para o `IOleInPlaceFrameWindow` interface:

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

O framework cuida do IUnknown porque ele sempre é necessário.

### <a name="interfacepart--macro-description"></a>INTERFACE_PART — Descrição da Macro

```cpp
INTERFACE_AGGREGATE(theClass, theAggr)
```

#### <a name="parameters"></a>Parâmetros

*theClass*<br/>
O nome da classe que contém o mapa da interface.

*theAggr*<br/>
O nome da variável de membro que deve ser agregada.

#### <a name="remarks"></a>Comentários

Essa macro é usada para informar a estrutura que a classe está usando um objeto agregado. Ele deve aparecer entre as macros BEGIN_INTERFACE_PART e END_INTERFACE_PART. Um objeto agregado é um objeto separado, derivado de [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown). Ao usar uma agregação e a macro INTERFACE_AGGREGATE, você pode fazer todas as interfaces que suportam agregados parecerem ser diretamente suportados pelo objeto. O *theAggr* argumento é simplesmente o nome de uma variável de membro da sua classe que deriva [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) (direta ou indiretamente). Todas as macros INTERFACE_AGGREGATE devem seguir as macros INTERFACE_PART quando colocada em um mapa de interface.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
