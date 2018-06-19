---
title: 'TN038: Implementação de IUnknown MFC OLE | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.mfc.ole
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e93c4e9d8707d3960e768b6929bb2b1c16d60b42
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33385457"
---
# <a name="tn038-mfcole-iunknown-implementation"></a>TN038: implementação de IUnknown MFC/OLE
> [!NOTE]
>  A Observação técnica a seguir não foi atualizada desde que ele foi incluído primeiro na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação on-line.  
  
 A essência do OLE 2 é o "OLE Component Object Model" ou COM. COM define um padrão para objetos trabalham em conjunto como se comunicar entre si. Isso inclui os detalhes do que um "objeto" aparência, incluindo como os métodos são distribuídos em um objeto. COM também define uma classe base, da qual todas as classes de compatível COM são derivadas. Essa classe base é [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509). Embora o [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) interface é conhecida como uma classe C++, COM não é específico a qualquer um idioma, pode ser implementado em C, PASCAL ou qualquer outra linguagem que pode dar suporte o layout binário de um objeto COM.  
  
 OLE refere-se a todas as classes derivadas de [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) como "interfaces". Essa é uma distinção importante, desde a "interface" como [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) não carrega nenhuma implementação. Ele simplesmente define o protocolo que objetos se comunicar, não as especificidades do que fazem as implementações. Isso é razoável para um sistema que permite flexibilidade máxima. É função do MFC para implementar um comportamento padrão para programas do MFC/C++.  
  
 Para entender a implementação do MFC de [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) você deve compreender o que é essa interface. Uma versão simplificada do [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) está definida abaixo:  
  
```  
class IUnknown  
{  
public:  
    virtual HRESULT QueryInterface(REFIID iid, void** ppvObj) = 0;  
    virtual ULONG AddRef() = 0;  
    virtual ULONG Release() = 0;  
};  
```  
  
> [!NOTE]
>  Detalhes de determinados convenção de chamada necessária, como `__stdcall` são deixados para ilustração.  
  
 O [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379) e [versão](http://msdn.microsoft.com/library/windows/desktop/ms682317) gerenciamento de memória do objeto de controle de funções de membro. COM usa um esquema de contagem de referência para manter o controle de objetos. Um objeto nunca é referenciado diretamente como você faria em C++. Em vez disso, os objetos são sempre referenciados através de um ponteiro. Para liberar o objeto quando o proprietário é feito usando o objeto do [versão](http://msdn.microsoft.com/library/windows/desktop/ms682317) é chamado de membro (em vez de usar o operador delete, como faria para um objeto C++ tradicional). A mecanismo de contagem de referência permite várias referências a um único objeto a ser gerenciado. Uma implementação de [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379) e [versão](http://msdn.microsoft.com/library/windows/desktop/ms682317) mantém uma contagem de referência no objeto, o objeto não é excluído até que a contagem de referência chega a zero.  
  
 [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379) e [versão](http://msdn.microsoft.com/library/windows/desktop/ms682317) são bem simples de um ponto de vista da implementação. Esta é uma implementação simples:  
  
```  
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
  
 O [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521) função de membro é um pouco mais interessante. Não é muito interessante para ter um objeto cujas somente funções de membro são [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379) e [versão](http://msdn.microsoft.com/library/windows/desktop/ms682317) — seria interessante informar o objeto para fazer coisas mais que [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) fornece. Isso é onde [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521) é útil. Ele permite que você obtenha uma "interface" diferente no mesmo objeto. Essas interfaces são normalmente derivadas de [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) e adiciona a funcionalidade adicional, adicionando novas funções de membro. Interfaces COM nunca têm variáveis de membro declaradas na interface e todas as funções de membro são declaradas como puro virtual. Por exemplo,  
  
```  
class IPrintInterface : public IUnknown  
{  
public:  
    virtual void PrintObject() = 0;  
};  
```  
  
 Para obter um IPrintInterface se você tiver apenas um [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509), chame [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521) usando o `IID` do **IPrintInterface**. Um `IID` é um número de 128 bits que identifica exclusivamente a interface. Há um `IID` para cada interface que definem a você ou OLE. Se `pUnk` é um ponteiro para um [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) do objeto, o código para recuperar um IPrintInterface dele pode ser:  
  
```  
IPrintInterface* pPrint = NULL;  
if (pUnk->QueryInterface(IID_IPrintInterface,   
 (void**)&pPrint) == NOERROR)  
{  
    pPrint->PrintObject();
pPrint->Release();
*// release pointer obtained via QueryInterface  
}  
```  
  
 Que parece relativamente fácil, mas como você implementa um objeto que oferece suporte a ambos o IPrintInterface e [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) interface nesse caso é simple porque o IPrintInterface deriva diretamente [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) — implementando IPrintInterface, [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) terá suporte automaticamente. Por exemplo:  
  
```  
class CPrintObj : public CPrintInterface  
{  
    virtual HRESULT QueryInterface(REFIID iid, void** ppvObj);

    virtual ULONG AddRef();
virtual ULONG Release();
virtual void PrintObject();

};  
```  
  
 As implementações de [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379) e [versão](http://msdn.microsoft.com/library/windows/desktop/ms682317) seria exatamente o mesmo que esses implementado acima. **CPrintObj::QueryInterface** deve ter esta aparência:  
  
```  
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
  
 Como você pode ver, se o identificador de interface (IID) for reconhecido, um ponteiro será retornado para o objeto. Caso contrário, ocorrerá um erro. Observe também que uma bem-sucedida [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521) resulta em um implícita [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379). Naturalmente, você também precisa implementar CEditObj::Print. É simple porque o IPrintInterface foi derivado diretamente o [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) interface. No entanto, se você quiser dar suporte a duas interfaces diferentes, ambos derivam de [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509), considere o seguinte:  
  
```  
class IEditInterface : public IUnkown  
{  
public:  
    virtual void EditObject() = 0;  
};  
```  
  
 Embora não haja um número de diferentes maneiras de implementar uma classe com suporte IEditInterface e IPrintInterface, incluindo o uso de C++ herança múltipla, essa observação se concentrará no uso de classes aninhadas para implementar essa funcionalidade.  
  
```  
class CEditPrintObj  
{  
public:  
    CEditPrintObj();

 
    HRESULT QueryInterface(REFIID iid,
    void**);

    ULONG AddRef();
ULONG Release();
DWORD m_dwRef;  
 
    class CPrintObj : public IPrintInterface  
 {  
    public: 
    CEditPrintObj* m_pParent;  
    virtual HRESULT QueryInterface(REFIID iid,
    void** ppvObj);

    virtual ULONG AddRef();
virtual ULONG Release();

 } m_printObj;  
 
    class CEditObj : public IEditInterface  
 {  
    public: 
    CEditPrintObj* m_pParent;  
    virtual ULONG QueryInterface(REFIID iid,
    void** ppvObj);

    virtual ULONG AddRef();
virtual ULONG Release();

 } m_editObj;  
};  
```  
  
 A implementação completa está incluída abaixo:  
  
```  
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
 
HRESULT CEditPrintObj::QueryInterface(REFIID iid,
    void** ppvObj)  
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
 
HRESULT CEditPrintObj::CEditObj::QueryInterface(
    REFIID iid,
    void** ppvObj)   
{   
    return m_pParent->QueryInterface(iid,
    ppvObj);

}  
 
ULONG CEditPrintObj::CPrintObj::AddRef()   
{   
    return m_pParent->AddRef();

}  
 
ULONG CEditPrintObj::CPrintObj::Release()   
{   
    return m_pParent->Release();

}  
 
HRESULT CEditPrintObj::CPrintObj::QueryInterface(
    REFIID iid,
    void** ppvObj)   
{   
    return m_pParent->QueryInterface(iid,
    ppvObj);

}  
```  
  
 Observe que a maioria do [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) implementação é colocada na classe CEditPrintObj em vez de duplicar o código em CEditPrintObj::CEditObj e CEditPrintObj::CPrintObj. Isso reduz a quantidade de código e evita erros. O ponto principal aqui é que da interface IUnknown é possível chamar [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521) qualquer interface de recuperar o objeto pode oferecer suporte a, e cada uma dessas interfaces, é possível fazer o mesmo. Isso significa que todos os [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521) funções disponíveis de cada interface devem se comportam exatamente da mesma maneira. Para esses objetos inseridos chamar a implementação no "objeto externo", um ponteiro back é usado (m_pParent). O ponteiro m_pParent é inicializado durante o construtor CEditPrintObj. Em seguida, você poderia implementar CEditPrintObj::CPrintObj::PrintObject e CEditPrintObj::CEditObj::EditObject também. Foi adicionado um pouco de código para adicionar um recurso, a capacidade de editar o objeto. Felizmente, é muito raro para interfaces ter apenas uma função de membro único (embora isso acontecer) e nesse caso, EditObject e PrintObject deve normalmente ser combinados em uma única interface.  
  
 É muito explicação e muito código para esse cenário simple. As classes MFC/OLE fornecem uma alternativa mais simples. A implementação do MFC usa uma técnica semelhante à maneira que mensagens do Windows são encapsuladas com mapas de mensagem. Esse recurso é chamado *mapas de Interface* e é abordado na próxima seção.  
  
## <a name="mfc-interface-maps"></a>Mapas de Interface do MFC  
 MFC/OLE inclui uma implementação de Interface "Maps" semelhante do MFC "Mapas de mensagem" e "Mapas de expedição" em execução e o conceito. Os principais recursos de mapas de Interface do MFC são da seguinte maneira:  
  
-   Uma implementação padrão de [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509), criados para o `CCmdTarget` classe.  
  
-   Manutenção da contagem de referência, modificada por [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379) e [versão](http://msdn.microsoft.com/library/windows/desktop/ms682317)  
  
-   Dados controlados por implementação de [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521)  
  
 Além disso, mapas de interface oferecem suporte a recursos avançados a seguir:  
  
-   Suporte para a criação de objetos agregáveis  
  
-   Suporte para usar objetos de agregação na implementação de um objeto COM  
  
-   A implementação é hookable e extensível  
  
 Para obter mais informações sobre a agregação, consulte o [agregação](http://msdn.microsoft.com/library/windows/desktop/ms686558\(v=vs.85\).aspx) tópico.  
  
 Suporte ao mapa de interface do MFC está enraizada na `CCmdTarget` classe. `CCmdTarget` "*tem um*" referência contagem, bem como todas as funções de membros associadas a [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) implementação (por exemplo é a contagem de referência em `CCmdTarget`). Para criar uma classe que dá suporte a OLE COM, você derivar uma classe de `CCmdTarget` e usar várias macros, bem como funções de membro `CCmdTarget` para implementar as interfaces desejadas. Implementação do MFC usa classes aninhadas para definir cada implementação de interface muito semelhante ao exemplo anterior. Isso é facilitado com uma implementação padrão de IUnknown, bem como um número de macros que eliminam a parte do código repetitivo.  
  
## <a name="interface-map-basics"></a>Noções básicas de mapa de interface  
  
#### <a name="to-implement-a-class-using-mfcs-interface-maps"></a>Para implementar uma classe usando a interface do MFC mapeia  
  
1.  Derive uma classe direta ou indiretamente de `CCmdTarget`.  
  
2.  Use o `DECLARE_INTERFACE_MAP` função na definição de classe derivada.  
  
3.  Para cada interface que você deseja dar suporte, use o `BEGIN_INTERFACE_PART` e `END_INTERFACE_PART` macros na definição de classe.  
  
4.  No arquivo de implementação, use o `BEGIN_INTERFACE_MAP` e `END_INTERFACE_MAP` macros para definir o mapa de interface da classe.  
  
5.  Para cada IID com suporte, use o `INTERFACE_PART` macro entre o `BEGIN_INTERFACE_MAP` e `END_INTERFACE_MAP` macros para mapear esse IID para um determinado "parte" da sua classe.  
  
6.  Implemente cada uma das classes aninhadas que representam as interfaces que você oferece suporte.  
  
7.  Use o `METHOD_PROLOGUE` macro para acessar o pai, `CCmdTarget`-objeto derivado.  
  
8. [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379), [versão](http://msdn.microsoft.com/library/windows/desktop/ms682317), e [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521) pode delegar para o `CCmdTarget` implementação dessas funções (`ExternalAddRef`, `ExternalRelease`, e `ExternalQueryInterface`).  
  
 O exemplo CPrintEditObj acima pode ser implementado da seguinte maneira:  
  
```  
class CPrintEditObj : public CCmdTarget  
{  
public: *// member data and member functions for CPrintEditObj go here  
 
// Interface Maps  
protected:  
    DECLARE_INTERFACE_MAP() 
 
    BEGIN_INTERFACE_PART(EditObj,
    IEditInterface)  
    STDMETHOD_(void,
    EditObject)();
END_INTERFACE_PART(EditObj) 
 
    BEGIN_INTERFACE_PART(PrintObj,
    IPrintInterface)  
    STDMETHOD_(void,
    PrintObject)();
END_INTERFACE_PART(PrintObj) 
};  
```  
  
 A declaração acima cria uma classe derivada de `CCmdTarget`. O `DECLARE_INTERFACE_MAP` macro informa a estrutura que essa classe terá um mapa de interface personalizada. Além disso, o `BEGIN_INTERFACE_PART` e `END_INTERFACE_PART` macros definem classes aninhadas, nesse caso com nomes CEditObj e CPrintObj (o X é usado somente para diferenciar as classes aninhadas das classes global que começam com "C" e a interface de classes que começam com "I "). Dois membros aninhados dessas classes são criados: m_CEditObj e m_CPrintObj, respectivamente. As macros automaticamente declarar o [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379), [versão](http://msdn.microsoft.com/library/windows/desktop/ms682317), e [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521) funções; portanto você apenas declarar as funções específicas a esta interface: EditObject e PrintObject (a macro OLE `STDMETHOD` é usado para que `_stdcall` e palavras-chave virtual são fornecidas conforme apropriado para a plataforma de destino).  
  
 Para implementar o mapa de interface para esta classe:  
  
```  
BEGIN_INTERFACE_MAP(CPrintEditObj,
    CCmdTarget)  
    INTERFACE_PART(CPrintEditObj,
    IID_IPrintInterface,
    PrintObj)  
    INTERFACE_PART(CPrintEditObj,
    IID_IEditInterface,
    EditObj)  
END_INTERFACE_MAP()  
```  
  
 Isso conecta o IID IID_IPrintInterface com m_CPrintObj e IID_IEditInterface com m_CEditObj respectivamente. O `CCmdTarget` implementação de [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521) (`CCmdTarget::ExternalQueryInterface`) usa esse mapa para retornar ponteiros para m_CPrintObj e m_CEditObj quando solicitado. Não é necessário incluir uma entrada para `IID_IUnknown`; o framework usará a primeira interface no mapa (nesse caso, m_CPrintObj) quando `IID_IUnknown` é solicitado.  
  
 Embora o `BEGIN_INTERFACE_PART` macro declarada automaticamente o [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379), [versão](http://msdn.microsoft.com/library/windows/desktop/ms682317) e [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521) funções para você, você ainda precisará implementá-las:  
  
```  
ULONG FAR EXPORT CEditPrintObj::XEditObj::AddRef()  
{  
    METHOD_PROLOGUE(CEditPrintObj,
    EditObj)  
    return pThis->ExternalAddRef();

}  
 
ULONG FAR EXPORT CEditPrintObj::XEditObj::Release()  
{  
    METHOD_PROLOGUE(CEditPrintObj,
    EditObj)  
    return pThis->ExternalRelease();

}  
 
HRESULT FAR EXPORT CEditPrintObj::XEditObj::QueryInterface(
    REFIID iid,
    void FAR* FAR* ppvObj)  
{  
    METHOD_PROLOGUE(CEditPrintObj,
    EditObj)  
    return (HRESULT)pThis->ExternalQueryInterface(&iid,
    ppvObj);

}  
 
void FAR EXPORT CEditPrintObj::XEditObj::EditObject()  
{  
    METHOD_PROLOGUE(CEditPrintObj,
    EditObj) *// code to "Edit" the object,
    whatever that means...  
}  
```  
  
 A implementação para CEditPrintObj::CPrintObj, seria semelhante para as definições acima para CEditPrintObj::CEditObj. Embora seria possível criar uma macro que pode ser usada para gerar automaticamente essas funções (mas anteriormente no desenvolvimento de MFC/OLE foi o caso), fica difícil definir pontos de interrupção quando uma macro gera mais de uma linha de código. Por esse motivo, esse código é expandido manualmente.  
  
 Usando a implementação do framework de mapas de mensagem, há várias coisas que não eram necessárias para fazer:  
  
-   Implementar QueryInterface  
  
-   Implementar AddRef e versão  
  
-   Declarar qualquer um desses métodos internos em ambas as interfaces  
  
 Além disso, a estrutura usa internamente mapas de mensagem. Isso permite que você derivar uma classe do framework, digamos que `COleServerDoc`, já que dá suporte a determinadas interfaces e fornece substituições ou adições às interfaces fornecidas pelo framework. Você pode fazer isso porque a estrutura dá suporte total ao herdar um mapa de interface de uma classe base. Essa é a razão por que `BEGIN_INTERFACE_MAP` usa como seu segundo parâmetro, o nome da classe base.  
  
> [!NOTE]
>  Geralmente não é possível reutilizar a implementação de implementações de internos do MFC das interfaces OLE apenas herdando a especialização incorporada da interface da versão do MFC. Não é possível porque o uso do `METHOD_PROLOGUE` macro para obter acesso a que contém `CCmdTarget`-objeto derivado implica um *deslocamento fixo* do objeto incorporado do `CCmdTarget`-objeto derivado. Isso significa, por exemplo, você não pode derivar um XMyAdviseSink incorporado da implementação do MFC em `COleClientItem::XAdviseSink`, pois XAdviseSink depende sendo em um deslocamento específico do início do `COleClientItem` objeto.  
  
> [!NOTE]
>  No entanto, poderá, delegar para a implementação do MFC para todas as funções que você deseja que o comportamento de padrão do MFC. Isso é feito na implementação do MFC `IOleInPlaceFrame` (XOleInPlaceFrame) na `COleFrameHook` classe (ela delega a m_xOleInPlaceUIWindow para muitas funções). Esse design foi escolhido para reduzir o tamanho de tempo de execução de objetos que implementam várias interfaces; Ele elimina a necessidade de um ponteiro back (como m_pParent a forma como foi usado na seção anterior).  
  
### <a name="aggregation-and-interface-maps"></a>Agregação e mapas de Interface  
 Além de oferecer suporte a objetos autônomos, MFC também oferece suporte à agregação. Agregação em si é um tópico muito complexo para discutir aqui; Consulte o [agregação](http://msdn.microsoft.com/library/windows/desktop/ms686558\(v=vs.85\).aspx) tópico para obter mais informações sobre a agregação. Esta anotação simplesmente descrevem o suporte para agregação incorporado os mapas de interface e do framework.  
  
 Há duas maneiras de usar a agregação: (1) usando um objeto COM que oferece suporte à agregação e (2) implementando um objeto que pode ser agregado por outro. Esses recursos podem ser denominados "usando um objeto agregado" e "fazendo um objeto agregável". MFC dá suporte a ambos.  
  
### <a name="using-an-aggregate-object"></a>Usando um objeto de agregação  
 Para usar um objeto de agregação, haverá necessidade de alguma forma para ligar a agregação para o mecanismo de QueryInterface. Em outras palavras, o objeto de agregação se comportam como se fosse parte do seu objeto nativo. Como essa associação na interface do MFC mapear mecanismo além de `INTERFACE_PART` macro, onde um objeto aninhado é mapeado para um IID, também é possível declarar um objeto de agregação como parte de sua `CCmdTarget` classe derivada. Para fazer isso, o `INTERFACE_AGGREGATE` macro é usada. Isso permite que você especifique uma variável de membro (que deve ser um ponteiro para um [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) ou classe derivada), que é integrada ao mecanismo de mapa de interface. Se o ponteiro não é nulo quando `CCmdTarget::ExternalQueryInterface` é chamado, a estrutura automaticamente chamar o objeto de agregação [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521) função de membro, se o `IID` solicitada não é um nativo `IID`s suporte a `CCmdTarget` objeto propriamente dito.  
  
##### <a name="to-use-the-interfaceaggregate-macro"></a>Para usar a macro INTERFACE_AGGREGATE  
  
1.  Declare uma variável de membro (um `IUnknown*`) que contém um ponteiro para o objeto de agregação.  
  
2.  Incluir um `INTERFACE_AGGREGATE` macro em seu mapa de interface, que se refere à variável de membro por nome.  
  
3.  Em algum momento (normalmente durante `CCmdTarget::OnCreateAggregates`), inicializar a variável de membro para algo diferente de NULL.  
  
 Por exemplo:  
  
```  
class CAggrExample : public CCmdTarget  
{  
public:  
    CAggrExample();

 
protected:  
    LPUNKNOWN m_lpAggrInner;  
    virtual BOOL OnCreateAggregates();

 
    DECLARE_INTERFACE_MAP() *// "native" interface part macros may be used here  
};  
 
CAggrExample::CAggrExample()  
{  
    m_lpAggrInner = NULL;  
}  
 
BOOL CAggrExample::OnCreateAggregates()  
{ *// wire up aggregate with correct controlling unknown  
    m_lpAggrInner = CoCreateInstance(CLSID_Example,  
    GetControllingUnknown(),
    CLSCTX_INPROC_SERVER,  
    IID_IUnknown, (LPVOID*)&m_lpAggrInner);

    if (m_lpAggrInner == NULL)  
    return FALSE; *// optionally,
    create other aggregate objects here  
    return TRUE;  
}  
 
BEGIN_INTERFACE_MAP(CAggrExample,
    CCmdTarget) *// native "INTERFACE_PART" entries go here  
    INTERFACE_AGGREGATE(CAggrExample,
    m_lpAggrInner)  
END_INTERFACE_MAP()  
```  
  
 A variável m_lpAggrInner é inicializada no construtor para NULL. A estrutura ignora uma variável de membro na implementação do padrão de NULL [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521). `OnCreateAggregates` é um bom lugar para criar os objetos de agregação. Você precisa chamar explicitamente se você estiver criando o objeto fora a implementação do MFC de `COleObjectFactory`. O motivo para criar agregações em `CCmdTarget::OnCreateAggregates` , bem como o uso de `CCmdTarget::GetControllingUnknown` ficará aparente quando criar objetos agregáveis é discutido.  
  
 Essa técnica lhe dará o objeto de todas as interfaces que o objeto de agregação dá suporte a mais de suas interfaces nativo. Se você desejar somente um subconjunto das interfaces que oferece suporte a agregação, você pode substituir `CCmdTarget::GetInterfaceHook`. Isso permite hookability nível muito baixo, semelhante ao [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521). Normalmente, você deseja que todas as interfaces que oferece suporte a agregação.  
  
### <a name="making-an-object-implementation-aggregatable"></a>Fazer uma implementação do objeto agregável  
 Para um objeto para ser agregáveis, a implementação de [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379), [versão](http://msdn.microsoft.com/library/windows/desktop/ms682317), e [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521) devem delegar para "desconhecido controlar". Em outras palavras, para que seja parte do objeto, ele deve delegar [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379), [versão](http://msdn.microsoft.com/library/windows/desktop/ms682317), e [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521) para um objeto diferente, também derivadas de [ IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509). Este "Controlando desconhecido" é fornecido para o objeto quando ele é criado, ou seja, ele é fornecido para a implementação de `COleObjectFactory`. Implementar isso traz uma pequena quantidade de sobrecarga e em alguns casos não é desejável, portanto MFC torna isso opcional. Para ativar um objeto para ser agregáveis, você deve chamar `CCmdTarget::EnableAggregation` do construtor do objeto.  
  
 Se o objeto também usa agregações, você também deve ser ser aprovado corretas "controlar desconhecido" para os objetos de agregação. Geralmente isso [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) ponteiro é passado para o objeto quando a agregação é criada. Por exemplo, o parâmetro pUnkOuter é o "controlar desconhecido" para objetos criados com `CoCreateInstance`. O ponteiro correta de "Controlando desconhecido" pode ser recuperado chamando `CCmdTarget::GetControllingUnknown`. O valor retornado da função, no entanto, não é válido durante o construtor. Por esse motivo, é recomendável que você crie sua agregações somente em uma substituição de `CCmdTarget::OnCreateAggregates`, onde o valor de retorno de `GetControllingUnknown` é confiável, mesmo se criado a partir de `COleObjectFactory` implementação.  
  
 Também é importante que o objeto manipule a contagem de referência correto ao adicionar ou liberar contagens de referência artificial. Para garantir que esse é o caso, sempre chamar `ExternalAddRef` e `ExternalRelease` em vez de `InternalRelease` e `InternalAddRef`. É raro para chamar `InternalRelease` ou `InternalAddRef` em uma classe que oferece suporte à agregação.  
  
### <a name="reference-material"></a>Material de referência  
 Uso avançado de OLE, como definir suas próprias interfaces ou substituir a implementação da estrutura das interfaces OLE requer o uso do mecanismo de mapa de interface subjacente.  
  
 Esta seção aborda cada macro e as APIs que são usadas para implementar esses recursos avançados.  
  
### <a name="ccmdtargetenableaggregation--function-description"></a>CCmdTarget::EnableAggregation — Descrição da função  
  
```  
 
void EnableAggregation();

 
```  
  
## <a name="remarks"></a>Comentários  
 Chame essa função no construtor de classe derivada, se você deseja dar suporte a agregação OLE para objetos desse tipo. Prepara uma implementação de IUnknown especial que é necessária para objetos agregáveis.  
  
### <a name="ccmdtargetexternalqueryinterface--function-description"></a>CCmdTarget::ExternalQueryInterface — Descrição da função  
  
```  
 
    DWORD ExternalQueryInterface(constvoidFAR* lpIID, LPVOIDFAR* ppvObj);
```  
  
## <a name="remarks"></a>Comentários  
  
#### <a name="parameters"></a>Parâmetros  
 `lpIID`  
 Um ponteiro de distância para um IID (o primeiro argumento QueryInterface)  
  
 `ppvObj`  
 Um ponteiro para um IUnknown * (segundo argumento para QueryInterface)  
  
## <a name="remarks"></a>Comentários  
 Chamar essa função em sua implementação de IUnknown para cada interface de sua classe implementa. Essa função fornece a implementação padrão de controladas por dados de QueryInterface com base no mapa de interface do objeto. É necessário converter o valor de retorno para um HRESULT. Se o objeto é agregado, essa função chamará "IUnknown controlador" em vez de usar o mapa de interface local.  
  
### <a name="ccmdtargetexternaladdref--function-description"></a>CCmdTarget::ExternalAddRef — Descrição da função  
  
```  
 
DWORD ExternalAddRef();

 
```  
  
## <a name="remarks"></a>Comentários  
 Chamar essa função em sua implementação de AddRef para cada interface de sua classe implementa. O valor de retorno é a nova contagem de referência no objeto CCmdTarget. Se o objeto é agregado, essa função chamará "IUnknown controlador" em vez de manipular a contagem de referência local.  
  
### <a name="ccmdtargetexternalrelease--function-description"></a>CCmdTarget::ExternalRelease — Descrição da função  
  
```  
 
DWORD ExternalRelease();

 
```  
  
## <a name="remarks"></a>Comentários  
 Chamar essa função em sua implementação de IUnknown para cada interface de sua classe implementa. O valor de retorno indica que a nova contagem de referência no objeto. Se o objeto é agregado, essa função chamará "IUnknown controlador" em vez de manipular a contagem de referência local.  
  
### <a name="declareinterfacemap--macro-description"></a>DECLARE_INTERFACE_MAP — Descrição da Macro  
  
```  
 
DECLARE_INTERFACE_MAP  
 
```  
  
## <a name="remarks"></a>Comentários  
 Use esta macro de qualquer classe derivada de `CCmdTarget` que terá um mapa de interface. Usado da mesma forma como `DECLARE_MESSAGE_MAP`. Esta chamada de macro deve ser colocada na definição de classe, geralmente em um cabeçalho (. H) arquivo. Uma classe com `DECLARE_INTERFACE_MAP` deve definir o mapa de interface no arquivo de implementação (. CPP) com o `BEGIN_INTERFACE_MAP` e `END_INTERFACE_MAP` macros.  
  
### <a name="begininterfacepart-and-endinterfacepart--macro-descriptions"></a>BEGIN_INTERFACE_PART e END_INTERFACE_PART — descrições de Macro  
  
```  
 
    BEGIN_INTERFACE_PART(
 localClass,   
    iface);

END_INTERFACE_PART(
 localClass)  
```  
  
## <a name="remarks"></a>Comentários  
  
#### <a name="parameters"></a>Parâmetros  
 `localClass`  
 O nome da classe que implementa a interface  
  
 `iface`  
 O nome da interface que esta classe implementa  
  
## <a name="remarks"></a>Comentários  
 Para cada interface implementa sua classe, você precisa ter um `BEGIN_INTERFACE_PART` e `END_INTERFACE_PART` par. Essas macros definem uma classe local derivada da interface OLE que você definir, bem como uma variável de membro inseridos dessa classe. O [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379), [versão](http://msdn.microsoft.com/library/windows/desktop/ms682317), e [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521) membros são declarados automaticamente. Você deve incluir as declarações para as outras funções de membro que fazem parte da interface que está sendo implementado (essas declarações são colocadas entre o `BEGIN_INTERFACE_PART` e `END_INTERFACE_PART` macros).  
  
 O `iface` argumento é a interface OLE que você deseja implementar, tal como `IAdviseSink`, ou `IPersistStorage` (ou sua própria interface personalizada).  
  
 O `localClass` argumento é o nome da classe local que será definido. Um ' X' será incluído automaticamente para o nome. Essa convenção de nomenclatura é usada para evitar colisões com classes global de mesmo nome. Além disso, o nome do membro inserido, mesmo que o `localClass` nome exceto o prefixo 'm_x'.  
  
 Por exemplo:  
  
```  
BEGIN_INTERFACE_PART(MyAdviseSink,
    IAdviseSink)  
    STDMETHOD_(void,
    OnDataChange)(LPFORMATETC,
    LPSTGMEDIUM);

    STDMETHOD_(void,
    OnViewChange)(DWORD,
    LONG);

    STDMETHOD_(void,
    OnRename)(LPMONIKER);

 STDMETHOD_(void,
    OnSave)();
STDMETHOD_(void,
    OnClose)();

END_INTERFACE_PART(MyAdviseSink) 
```  
  
 define uma classe local chamada XMyAdviseSink derivado de IAdviseSink e um membro da classe no qual ela é declarada chamado m_xMyAdviseSink.Note:  
  
> [!NOTE]
>  As linhas que começam com `STDMETHOD`_ essencialmente são copiados do OLE2. H e ligeiramente modificados. Copiando-os de OLE2. H pode reduzir os erros que são difíceis de resolver.  
  
### <a name="begininterfacemap-and-endinterfacemap--macro-descriptions"></a>BEGIN_INTERFACE_MAP e END_INTERFACE_MAP — descrições de Macro  
  
```  
 
    BEGIN_INTERFACE_MAP(
 theClass,   
    baseClass)END_INTERFACE_MAP 
```  
  
## <a name="remarks"></a>Comentários  
  
#### <a name="parameters"></a>Parâmetros  
 `theClass`  
 A classe na qual o mapa de interface é a ser definido  
  
 `baseClass`  
 A classe da qual `theClass` deriva.  
  
## <a name="remarks"></a>Comentários  
 O `BEGIN_INTERFACE_MAP` e `END_INTERFACE_MAP` macros são usadas no arquivo de implementação para realmente definir o mapa de interface. Para cada interface implementada há um ou mais `INTERFACE_PART` invocações de macro. Para cada agregação, que usa a classe, há um `INTERFACE_AGGREGATE` invocação de macro.  
  
### <a name="interfacepart--macro-description"></a>INTERFACE_PART — Descrição da Macro  
  
```  
 
    INTERFACE_PART(
 theClass,   
    iid, 
    localClass) 
```  
  
## <a name="remarks"></a>Comentários  
  
#### <a name="parameters"></a>Parâmetros  
 `theClass`  
 O nome da classe que contém o mapa de interface.  
  
 `iid`  
 O `IID` que está para ser mapeado para a classe incorporada.  
  
 `localClass`  
 O nome da classe local (menos 'X').  
  
## <a name="remarks"></a>Comentários  
 Essa macro é usada entre o `BEGIN_INTERFACE_MAP` macro e `END_INTERFACE_MAP` macro para cada interface que seu objeto oferecerá suporte. Ele permite que você mapeie um IID para um membro da classe indicado pelo `theClass` e `localClass`. 'm_x' serão adicionados para o `localClass` automaticamente. Observe que mais de um `IID` pode ser associado um único membro. Isso é muito útil quando você estiver implementando somente uma interface de "mais derivados" e deseja fornecer todas as interfaces intermediárias. Um bom exemplo disso é o `IOleInPlaceFrameWindow` interface. Sua hierarquia tem esta aparência:  
  
```  
IUnknown  
    IOleWindow 
    IOleUIWindow 
    IOleInPlaceFrameWindow 
```  
  
 Se um objeto que implementa `IOleInPlaceFrameWindow`, um cliente pode `QueryInterface` em qualquer uma dessas interfaces: `IOleUIWindow`, `IOleWindow`, ou [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509), além de interface "mais derivada" `IOleInPlaceFrameWindow` (aquela que estejam de fato Implementando). Para lidar com isso, você pode usar mais de um `INTERFACE_PART` macro para mapear cada interface base para o `IOleInPlaceFrameWindow` interface:  
  
 no arquivo de definição de classe:  
  
```  
BEGIN_INTERFACE_PART(CMyFrameWindow, IOleInPlaceFrameWindow)  
```  
  
 no arquivo de implementação da classe:  
  
```  
BEGIN_INTERFACE_MAP(CMyWnd,
    CFrameWnd)  
    INTERFACE_PART(CMyWnd,
    IID_IOleWindow,
    MyFrameWindow)  
    INTERFACE_PART(CMyWnd,
    IID_IOleUIWindow,
    MyFrameWindow)  
    INTERFACE_PART(CMyWnd,
    IID_IOleInPlaceFrameWindow,
    MyFrameWindow)  
END_INTERFACE_MAP  
```  
  
 A estrutura cuida IUnknown porque ele é sempre necessário.  
  
### <a name="interfacepart--macro-description"></a>INTERFACE_PART — Descrição da Macro  
  
```  
 
    INTERFACE_AGGREGATE(
 theClass,   
    theAggr) 
```  
  
## <a name="remarks"></a>Comentários  
  
#### <a name="parameters"></a>Parâmetros  
 `theClass`  
 O nome da classe que contém o mapa de interface  
  
 `theAggr`  
 O nome da variável de membro que será agregado.  
  
## <a name="remarks"></a>Comentários  
 Essa macro é usada para informar a estrutura que a classe está usando um objeto de agregação. Ele deve aparecer entre o `BEGIN_INTERFACE_PART` e `END_INTERFACE_PART` macros. Um objeto de agregação é um objeto separado, derivado do [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509). Usando uma agregação e o `INTERFACE_AGGREGATE` macro, você pode fazer todas as interfaces que o oferece suporte à agregação parecem ser diretamente o objeto oferece suporte. O `theAggr` argumento é simplesmente o nome de uma variável de membro da classe que é derivada de [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) (direta ou indiretamente). Todos os `INTERFACE_AGGREGATE` macros devem seguir o `INTERFACE_PART` macros quando colocada em um mapa de interface.  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

