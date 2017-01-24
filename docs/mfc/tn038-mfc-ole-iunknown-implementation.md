---
title: "TN038: implementa&#231;&#227;o de IUnknown MFC/OLE | Microsoft Docs"
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
  - "vc.mfc.ole"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "macros de agregação [C++]"
  - "Macro BEGIN_INTERFACE_MAP"
  - "Macro BEGIN_INTERFACE_PART"
  - "Interfaces COM, interface base"
  - "Macro DECLARE_INTERFACE_MAP"
  - "Macro END_INTERFACE_MAP"
  - "Macro END_INTERFACE_PART"
  - "Macro INTERFACE_PART"
  - "Interface IUnknown"
  - "Macro METHOD_PROLOGUE"
  - "OLE [C++], implementando a interface IUnknown"
  - "Macro STDMETHOD"
  - "TN038"
ms.assetid: 19d946ba-beaf-4881-85c6-0b598d7f6f11
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN038: implementa&#231;&#227;o de IUnknown MFC/OLE
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  Esta nota técnica não foi atualizada desde que ele foi incluído pela primeira vez na documentação online.  Como resultado, alguns procedimentos e tópicos podem ser desatualizado ou incorreto.  Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação on\-line.  
  
 No coração do OLE 2 é o "OLE Component Object Model" ou COM.  COM define um padrão para objetos cooperativos como se comunicar entre si.  Isso inclui os detalhes de que um "objeto" aparência, incluindo como os métodos são distribuídos em um objeto.  COM também define uma classe base, do qual todas as classes compatíveis COM são derivadas.  Essa classe base é [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509).  Embora o [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) interface é conhecido como uma classe C\+\+, COM não é específico para qualquer um idioma — ele pode ser implementado em C, PASCAL ou qualquer outra linguagem compatível com o layout binário de um objeto COM.  
  
 OLE refere\-se a todas as classes derivadas de [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) como interfaces"." Essa é uma distinção importante, desde uma "interface" como [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) não carrega nenhuma implementação.  Ele simplesmente define o protocolo pelo qual objetos se comunicar, não as especificidades do que fazem essas implementações.  Isso é razoável para um sistema que permite a máxima flexibilidade.  É função do MFC para implementar um comportamento padrão para programas MFC\/C\+\+.  
  
 Para entender a implementação do MFC de [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) você deve primeiro compreender o que é essa interface.  Uma versão simplificada do [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) definido abaixo:  
  
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
>  Detalhes de determinados convenção de chamada necessária, como `__stdcall` ficam de ilustração.  
  
 O [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379) e [versão](http://msdn.microsoft.com/library/windows/desktop/ms682317) gerenciamento de memória do objeto de controle de funções de membro.  COM usa um esquema de contagem de referência para controlar objetos.  Um objeto nunca é referenciado diretamente como faria em C\+\+.  Em vez disso, os objetos são sempre referenciados através de um ponteiro.  Para liberar o objeto quando o proprietário é feito usando o objeto do [versão](http://msdn.microsoft.com/library/windows/desktop/ms682317) membro é chamado \(em vez de usar o operador delete, como faria para um objeto C\+\+ tradicional\).  A mecanismo de contagem de referência permite várias referências a um único objeto para ser gerenciado.  Uma implementação de [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379) e [versão](http://msdn.microsoft.com/library/windows/desktop/ms682317) mantém uma contagem de referência no objeto, o objeto não é excluído até sua contagem de referência chega a zero.  
  
 [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379) e [versão](http://msdn.microsoft.com/library/windows/desktop/ms682317) são bem simples de um ponto de vista de implementação.  Aqui está uma implementação simples:  
  
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
  
 O [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521) função de membro é um pouco mais interessante.  Não é muito interessante ter um objeto cujas somente funções de membro são [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379) e [versão](http://msdn.microsoft.com/library/windows/desktop/ms682317) — seria bom informar ao objeto fazer mais coisas que [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) fornece.  É aí que [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521) é útil.  Ele permite que você obtenha uma "interface" diferente no mesmo objeto.  Essas interfaces são normalmente derivadas de [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) e adicionar funcionalidade adicional, adicionando novas funções de membro.  Interfaces COM nunca tem variáveis de membro declaradas na interface do, e todas as funções de membro são declaradas como puro virtual.  Por exemplo,  
  
```  
class IPrintInterface : public IUnknown  
{  
public:  
    virtual void PrintObject() = 0;  
};  
```  
  
 Para obter um IPrintInterface se você tiver apenas um [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509), chame [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521) usando o `IID` do **IPrintInterface**.  Um `IID` é um número de 128 bits que identifica com exclusividade a interface.  Há um `IID` para cada interface que você ou OLE definem.  Se `pUnk` é um ponteiro para um [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) do objeto, o código para recuperar um IPrintInterface dele pode ser:  
  
```  
IPrintInterface* pPrint = NULL;  
if (pUnk->QueryInterface(IID_IPrintInterface,   
    (void**)&pPrint) == NOERROR)  
{  
    pPrint->PrintObject();  
    pPrint->Release();     
        // release pointer obtained via QueryInterface  
}  
```  
  
 Isso parece relativamente fácil, mas como você implementa um objeto que oferece suporte a ambos os IPrintInterface e [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) interface?  Nesse caso é simple como o IPrintInterface é derivada diretamente de [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) — implementando IPrintInterface, [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) automaticamente com suporte.  Por exemplo:  
  
```  
class CPrintObj : public CPrintInterface  
{  
    virtual HRESULT QueryInterface(REFIID iid, void** ppvObj);  
    virtual ULONG AddRef();  
    virtual ULONG Release();  
    virtual void PrintObject();  
};  
```  
  
 As implementações de [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379) e [versão](http://msdn.microsoft.com/library/windows/desktop/ms682317) seria exatamente o mesmo que esses implementada acima.  **CPrintObj::QueryInterface** poderia ter esta aparência:  
  
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
  
 Como você pode ver, se o identificador de interface \(IID\) for reconhecido, um ponteiro é retornado para o objeto; Caso contrário, ocorrerá um erro.  Observe também que bem\-sucedida [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521) resulta em um implícita [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379).  É claro, você também precisará implementar CEditObj::Print.  Isso é simple porque provenientes diretamente o IPrintInterface o [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) interface.  No entanto, se você quisesse oferecer suporte a duas interfaces diferentes, ambas derivam [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509), considere o seguinte:  
  
```  
class IEditInterface : public IUnkown  
{  
public:  
    virtual void EditObject() = 0;  
};  
```  
  
 Embora haja várias maneiras diferentes de implementar uma classe com suporte para IEditInterface e IPrintInterface, inclusive usando C\+\+ herança múltipla, esta nota se concentrará no uso de classes aninhadas para implementar essa funcionalidade.  
  
```  
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
  
 Toda a implementação está incluída abaixo:  
  
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
  
HRESULT CEditPrintObj::CEditObj::QueryInterface(  
    REFIID iid, void** ppvObj)   
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
  
HRESULT CEditPrintObj::CPrintObj::QueryInterface(  
    REFIID iid, void** ppvObj)   
{   
    return m_pParent->QueryInterface(iid, ppvObj);   
}  
```  
  
 Observe que a maioria do [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) implementação é colocada na classe CEditPrintObj em vez de duplicar o código no CEditPrintObj::CEditObj e CEditPrintObj::CPrintObj.  Isso reduz a quantidade de código e evita bugs.  O ponto principal aqui é que da interface IUnknown é possível chamar [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521) recuperar qualquer interface de objeto pode dar suporte e de cada uma dessas interfaces, é possível fazer o mesmo.  Isso significa que todos os [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521) funções disponíveis de cada interface devem se comportar exatamente da mesma maneira.  Para esses objetos inseridos chamar a implementação em "objeto externo", um ponteiro back é usado \(m\_pParent\).  O ponteiro m\_pParent é inicializado durante o construtor CEditPrintObj.  Em seguida, você poderia implementar CEditPrintObj::CPrintObj::PrintObject e CEditPrintObj::CEditObj::EditObject também.  Foi adicionado um pouco de código para adicionar um recurso — a capacidade de editar o objeto.  Felizmente, é bastante incomum para interfaces de ter apenas uma única função de membro \(embora isso acontecer\) e nesse caso, EditObject e PrintObject seriam normalmente ser combinadas em uma única interface.  
  
 Isso é muita explicação e muito código para esse cenário simple.  As classes do MFC\/OLE fornecem uma alternativa mais simples.  A implementação do MFC usa uma técnica semelhante à forma como as mensagens do Windows são encapsuladas com mapas de mensagem.  Esse recurso é chamado *mapas de Interface* e é abordado na próxima seção.  
  
## Mapas de Interface do MFC  
 MFC\/OLE inclui uma implementação da Interface "Maps" semelhantes do MFC "Mapas de mensagem" e "Mapas de expedição" em conceito e execução.  Os principais recursos dos mapas de Interface do MFC são os seguintes:  
  
-   Uma implementação padrão de [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509), criado para o `CCmdTarget` classe.  
  
-   Manutenção da contagem de referência, modificada por [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379) e [versão](http://msdn.microsoft.com/library/windows/desktop/ms682317)  
  
-   Implementação de orientados a dados [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521)  
  
 Além disso, mapas de interface suportam os seguintes recursos avançados:  
  
-   Suporte à criação de objetos agregáveis  
  
-   Suporte para usar objetos de agregação na implementação de um objeto COM  
  
-   A implementação é extensível e hookable  
  
 Para obter mais informações sobre a agregação, consulte o [agregação](http://msdn.microsoft.com/library/windows/desktop/ms686558\(v=vs.85\).aspx) topic.  
  
 Suporte ao mapa de interface do MFC está enraizada no `CCmdTarget` classe.  `CCmdTarget` "*tem um*" referência de contagem, bem como todas as funções de membro associadas a [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) implementação \(por exemplo é a contagem de referência em `CCmdTarget`\).  Para criar uma classe que oferece suporte a OLE COM, você derivar uma classe de `CCmdTarget` e usar várias macros, bem como funções de membro `CCmdTarget` para implementar as interfaces desejadas.  Implementação do MFC usa classes aninhadas para definir cada implementação de interface muito semelhante ao exemplo anterior.  Isso é mais fácil com uma implementação padrão de IUnknown, bem como um número de macros que eliminam alguns códigos repetitivos.  
  
## Noções básicas sobre o mapa de interface  
  
#### Para implementar uma classe usando a interface do MFC mapeia  
  
1.  Derivar uma classe direta ou indiretamente de `CCmdTarget`.  
  
2.  Use o `DECLARE_INTERFACE_MAP` função na definição de classe derivada.  
  
3.  Para cada interface que você deseja dar suporte, use o `BEGIN_INTERFACE_PART` e `END_INTERFACE_PART` macros na definição de classe.  
  
4.  No arquivo de implementação, use o `BEGIN_INTERFACE_MAP` e `END_INTERFACE_MAP` macros para definir o mapa de interface da classe.  
  
5.  Para cada IID com suporte, use o `INTERFACE_PART` macro entre o `BEGIN_INTERFACE_MAP` e `END_INTERFACE_MAP` macros para mapear esse IID para uma determinada "parte" de sua classe.  
  
6.  Implemente cada uma das classes aninhadas que representam as interfaces que você dá suporte.  
  
7.  Use o `METHOD_PROLOGUE` macro para acessar o pai, `CCmdTarget`\-objeto derivado.  
  
8.  [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379), [versão](http://msdn.microsoft.com/library/windows/desktop/ms682317), e [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521) pode delegar para a `CCmdTarget` implementação dessas funções \(`ExternalAddRef`, `ExternalRelease`, e `ExternalQueryInterface`\).  
  
 O exemplo CPrintEditObj acima poderia ser implementado da seguinte maneira:  
  
```  
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
  
 A declaração acima cria uma classe derivada de `CCmdTarget`.  O `DECLARE_INTERFACE_MAP` macro informa a estrutura que essa classe terá um mapa de interface personalizada.  Além disso, a `BEGIN_INTERFACE_PART` e `END_INTERFACE_PART` macros definem classes aninhadas, nesse caso com nomes CEditObj e CPrintObj \(X é usado somente para diferenciar as classes aninhadas global classes que começam com "C" e a interface de classes que começam com "I"\).  São criados dois membros dessas classes aninhados: m\_CEditObj e m\_CPrintObj, respectivamente.  As macros declaram automaticamente o [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379), [versão](http://msdn.microsoft.com/library/windows/desktop/ms682317), e [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521) funciona; portanto você apenas declarar as funções específicas para essa interface: EditObject e PrintObject \(a macro OLE `STDMETHOD` é usado para que `_stdcall` e palavras\-chave virtual são fornecidas conforme apropriado para a plataforma de destino\).  
  
 Para implementar o mapa de interface para esta classe:  
  
```  
BEGIN_INTERFACE_MAP(CPrintEditObj, CCmdTarget)  
    INTERFACE_PART(CPrintEditObj, IID_IPrintInterface, PrintObj)  
    INTERFACE_PART(CPrintEditObj, IID_IEditInterface, EditObj)  
END_INTERFACE_MAP()  
```  
  
 Isso conecta o IID IID\_IPrintInterface com m\_CPrintObj e IID\_IEditInterface com m\_CEditObj respectivamente.  O `CCmdTarget` implementação de [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521) \(`CCmdTarget::ExternalQueryInterface`\) usa esse mapa para retornam ponteiros para m\_CPrintObj e m\_CEditObj quando solicitado.  Não é necessário incluir uma entrada para `IID_IUnknown`; o framework usará a primeira interface no mapa \(nesse caso, m\_CPrintObj\) quando `IID_IUnknown` é solicitada.  
  
 Embora o `BEGIN_INTERFACE_PART` macro automaticamente declarada o [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379), [versão](http://msdn.microsoft.com/library/windows/desktop/ms682317) e [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521) funções para você, ainda é necessário implementá\-las:  
  
```  
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
    REFIID iid, void FAR* FAR* ppvObj)  
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
  
 A implementação de CEditPrintObj::CPrintObj, seria semelhante às definições acima para CEditPrintObj::CEditObj.  Embora seria possível criar uma macro que poderia ser usada para gerar automaticamente essas funções \(mas, no início do desenvolvimento do MFC\/OLE esse era o caso\), é difícil definir pontos de interrupção quando uma macro gera mais de uma linha de código.  Por esse motivo, esse código é expandido manualmente.  
  
 Usando a implementação do framework de mapas de mensagem, há várias coisas que não eram necessárias para fazer:  
  
-   Implementar QueryInterface  
  
-   Implementar AddRef e Release  
  
-   Declarar qualquer um desses métodos internos em ambas as interfaces  
  
 Além disso, a estrutura usa internamente mapas de mensagem.  Isso permite que você derivar uma classe do framework, digamos `COleServerDoc`, já que oferece suporte a certas interfaces e fornece substituições ou adições para as interfaces fornecidas pela estrutura.  Você pode fazer isso porque a estrutura é totalmente compatível com um mapa de interface herdando da classe base.  Essa é a razão por que `BEGIN_INTERFACE_MAP` utiliza como seu segundo parâmetro, o nome da classe base.  
  
> [!NOTE]
>  Geralmente não é possível reutilizar a implementação das implementações internas do MFC das interfaces OLE apenas herdando a especialização incorporada da interface da versão MFC.  Não é possível porque o uso do `METHOD_PROLOGUE` macro para obter acesso ao recipiente `CCmdTarget`\-objeto derivado implica um *deslocamento fixo* do objeto incorporado do `CCmdTarget`\-objeto derivado.  Isso significa, por exemplo, você não pode derivar um XMyAdviseSink incorporado da implementação do MFC no `COleClientItem::XAdviseSink`, pois XAdviseSink depende sendo em um deslocamento específico da parte superior do `COleClientItem` objeto.  
  
> [!NOTE]
>  Você pode, entretanto, delegar para a implementação do MFC para todas as funções que você deseja que o comportamento de padrão do MFC.  Isso é feito na implementação do MFC `IOleInPlaceFrame` \(XOleInPlaceFrame\) na `COleFrameHook` classe \(ela delega a m\_xOleInPlaceUIWindow para muitas funções\).  Esse design foi escolhido para reduzir o tamanho de tempo de execução dos objetos que implementam várias interfaces; Ele elimina a necessidade de um ponteiro back \(por exemplo, a maneira m\_pParent foi usado na seção anterior\).  
  
### Agregação e mapas de Interface  
 Além de oferecer suporte a objetos autônomos, o MFC também oferece suporte à agregação.  Agregação em si é um tópico muito complexo para discutir aqui; Consulte o [agregação](http://msdn.microsoft.com/library/windows/desktop/ms686558\(v=vs.85\).aspx) topic for more information on aggregation.  Esta nota simplesmente descreve o suporte para agregação incorporado os mapas de interface e estrutura.  
  
 Há duas maneiras de usar a agregação: \(1\) usando um objeto COM que oferece suporte à agregação e \(2\) implementa um objeto que pode ser agregado por outro.  Esses recursos podem ser denominados "usando um objeto de agregação" e "fazendo um objeto agregável".  MFC oferece suporte a ambos.  
  
### Usando um objeto de agregação  
 Para usar um objeto de agregação, haverá necessidade de vincular a agregação para o mecanismo de QueryInterface de alguma forma.  Em outras palavras, o objeto de agregação se comportam como se fosse uma parte nativa do objeto.  Assim como faz essa ligação ao mecanismo de mapa de interface do MFC?  Além de `INTERFACE_PART` macro, onde um objeto aninhado é mapeado para uma IID, você também pode declarar um objeto de agregação como parte de seu `CCmdTarget` classe derivada.  Para fazer isso, o `INTERFACE_AGGREGATE` macro é usado.  Isso permite que você especifique uma variável de membro \(que deve ser um ponteiro para um [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) ou classe derivada\), que é a ser integrado ao mecanismo de mapa de interface.  Se o ponteiro não é nulo quando `CCmdTarget::ExternalQueryInterface` é chamado, a estrutura automaticamente chamará o objeto de agregação [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521) função do membro, se o `IID` solicitado não é um dos nativo `IID`s compatíveis com o `CCmdTarget` próprio objeto.  
  
##### Para usar a macro INTERFACE\_AGGREGATE  
  
1.  Declare uma variável de membro \(um `IUnknown*`\) que contém um ponteiro para o objeto de agregação.  
  
2.  Incluir um `INTERFACE_AGGREGATE` macro em seu mapa de interface, que se refere à variável de membro por nome.  
  
3.  Em algum momento \(normalmente durante `CCmdTarget::OnCreateAggregates`\), inicialize a variável de membro para algo diferente de NULL.  
  
 Por exemplo:  
  
```  
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
  
 A variável m\_lpAggrInner é inicializada no construtor como NULL.  O framework ignora uma variável de membro NULL na implementação do padrão [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521).  `OnCreateAggregates` é um bom lugar para criar os objetos de agregação.  Você precisará chamar explicitamente se você estiver criando o objeto fora a implementação do MFC de `COleObjectFactory`.  O motivo para criar agregações no `CCmdTarget::OnCreateAggregates` bem como o uso de `CCmdTarget::GetControllingUnknown` se tornará aparente quando criar objetos agregáveis é discutido.  
  
 Essa técnica lhe dará o objeto de todas as interfaces compatíveis com o objeto de agregação além de suas interfaces nativas.  Se você quiser apenas um subconjunto das interfaces que oferece suporte a agregação, você pode substituir `CCmdTarget::GetInterfaceHook`.  Isso permite hookability nível muito baixo, semelhante ao [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521).  Normalmente, você deseja que todas as interfaces que oferece suporte a agregação.  
  
### Fazendo uma implementação do objeto agregável  
 Um objeto ser agregáveis, a implementação de [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379), [versão](http://msdn.microsoft.com/library/windows/desktop/ms682317), e [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521) deve delegar para "desconhecido controle". Em outras palavras, para que seja parte do objeto, ele deve delegar [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379), [versão](http://msdn.microsoft.com/library/windows/desktop/ms682317), e [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521) para um objeto diferente, também deriva [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509).  Este "Controlando desconhecido" é fornecido para o objeto quando ele é criado, ou seja, ele é fornecido para a implementação de `COleObjectFactory`.  Implementar isso apresenta uma pequena quantidade de sobrecarga e em alguns casos não é desejável, então MFC faz isso opcional.  Para ativar um objeto a ser agregáveis, chame `CCmdTarget::EnableAggregation` do construtor do objeto.  
  
 Se o objeto também usa agregações, você também deve ser precisa ser aprovado correta "controlar desconhecido" para os objetos de agregação.  Geralmente isso [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) ponteiro é passado para o objeto quando a agregação é criada.  Por exemplo, o parâmetro pUnkOuter é o "controlar desconhecido" para objetos criados com `CoCreateInstance`.  O ponteiro correto "Controlando desconhecido" pode ser recuperado chamando `CCmdTarget::GetControllingUnknown`.  O valor retornado da função que, no entanto, não é válido durante o construtor.  Por esse motivo, é recomendável que você crie suas agregações apenas em uma substituição de `CCmdTarget::OnCreateAggregates`, onde o valor de retorno de `GetControllingUnknown` é confiável, mesmo se criado a partir de `COleObjectFactory` implementação.  
  
 Também é importante que o objeto manipule a contagem de referência correta ao adicionar ou liberar contagens de referência artificial.  Para garantir que esse é o caso, sempre chamar `ExternalAddRef` e `ExternalRelease` em vez de `InternalRelease` e `InternalAddRef`.  É raro para chamar `InternalRelease` ou `InternalAddRef` em uma classe que oferece suporte à agregação.  
  
### Material de referência  
 Uso avançado do OLE, como definir suas próprias interfaces ou substituir a implementação da estrutura das interfaces OLE requer o uso do mecanismo de mapa de interface subjacente.  
  
 Esta seção aborda cada macro e as APIs que são usadas para implementar esses recursos avançados.  
  
### CCmdTarget::EnableAggregation — Descrição de função  
  
```  
  
void EnableAggregation();  
```  
  
## Observações  
 Chame essa função no construtor da classe derivada se desejar oferecer suporte à agregação OLE para objetos desse tipo.  Prepara uma implementação de IUnknown especial que é necessária para objetos agregáveis.  
  
### CCmdTarget::ExternalQueryInterface — Descrição de função  
  
```  
  
              DWORD ExternalQueryInterface(    const void FAR* lpIID,    LPVOID FAR* ppvObj   
);  
```  
  
## Observações  
  
#### Parâmetros  
 `lpIID`  
 Um ponteiro longe para um IID \(o primeiro argumento para QueryInterface\)  
  
 `ppvObj`  
 Um ponteiro para um IUnknown \* \(segundo argumento para QueryInterface\)  
  
## Observações  
 Chamar essa função em sua implementação de IUnknown para cada interface de sua classe implementa.  Essa função fornece a implementação padrão de orientados a dados de QueryInterface com base no mapa de interface do objeto.  É necessário converter o valor de retorno HRESULT.  Se o objeto é agregado, esta função irá chamar "IUnknown controlador" em vez de usar o mapa de interface local.  
  
### CCmdTarget::ExternalAddRef — Descrição de função  
  
```  
  
DWORD ExternalAddRef();  
```  
  
## Observações  
 Chamar essa função em sua implementação de AddRef para cada interface de sua classe implementa.  O valor de retorno é a nova contagem de referência no objeto CCmdTarget.  Se o objeto é agregado, esta função irá chamar "IUnknown controlador" em vez de manipular a contagem de referência local.  
  
### CCmdTarget::ExternalRelease — Descrição de função  
  
```  
  
DWORD ExternalRelease();  
  
```  
  
## Observações  
 Chamar essa função em sua implementação de IUnknown para cada interface de sua classe implementa.  O valor de retorno indica a nova contagem de referência no objeto.  Se o objeto é agregado, esta função irá chamar "IUnknown controlador" em vez de manipular a contagem de referência local.  
  
### DECLARE\_INTERFACE\_MAP — Descrição da Macro  
  
```  
  
DECLARE_INTERFACE_MAP  
  
```  
  
## Observações  
 Usar essa macro em qualquer classe derivada de `CCmdTarget` que terá um mapa de interface.  Usado da mesma forma como `DECLARE_MESSAGE_MAP`.  Esta chamada de macro deve ser colocada na definição de classe, geralmente em um cabeçalho \(. H\) arquivo.  Uma classe com `DECLARE_INTERFACE_MAP` deve definir o mapa de interface no arquivo de implementação \(. CPP\) com o `BEGIN_INTERFACE_MAP` e `END_INTERFACE_MAP` macros.  
  
### BEGIN\_INTERFACE\_PART e END\_INTERFACE\_PART — descrições de Macro  
  
```  
  
              BEGIN_INTERFACE_PART(   
   localClass,  
   iface   
);  
END_INTERFACE_PART(   
   localClass   
)  
```  
  
## Observações  
  
#### Parâmetros  
 l`ocalClass`  
 O nome da classe que implementa a interface  
  
 `iface`  
 O nome da interface que essa classe implementa  
  
## Observações  
 Para cada interface que sua classe implementará, você precisa ter um `BEGIN_INTERFACE_PART` e `END_INTERFACE_PART` par.  Essas macros definem uma classe local derivada da interface OLE que você define, bem como uma variável de membro inseridos dessa classe.  O [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379), [versão](http://msdn.microsoft.com/library/windows/desktop/ms682317), e [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521) membros são declarados automaticamente.  Você deve incluir as declarações para as outras funções de membro que fazem parte da interface que estão sendo implementada \(essas declarações são colocadas entre o `BEGIN_INTERFACE_PART` e `END_INTERFACE_PART` macros\).  
  
 O `iface` é a interface OLE que você deseja implementar, tal como `IAdviseSink`, ou `IPersistStorage` \(ou sua própria interface personalizada\).  
  
 O `localClass` argumento é o nome da classe local que será definido.  Um ' X' será incluído automaticamente ao nome.  Essa convenção de nomenclatura é usada para evitar colisões com classes global do mesmo nome.  Além disso, o nome do membro incorporado, mesmo que o `localClass` nome exceto o prefixo 'm\_x'.  
  
 Por exemplo:  
  
```  
BEGIN_INTERFACE_PART(MyAdviseSink, IAdviseSink)  
   STDMETHOD_(void,OnDataChange)(LPFORMATETC, LPSTGMEDIUM);  
   STDMETHOD_(void,OnViewChange)(DWORD, LONG);  
   STDMETHOD_(void,OnRename)(LPMONIKER);  
   STDMETHOD_(void,OnSave)();  
   STDMETHOD_(void,OnClose)();  
END_INTERFACE_PART(MyAdviseSink)  
```  
  
 define uma classe local chamada XMyAdviseSink derivado de IAdviseSink e um membro da classe na qual ela é declarada chamado m\_xMyAdviseSink.Note:  
  
> [!NOTE]
>  As linhas que começam com `STDMETHOD`\_ essencialmente são copiados do OLE2. H e ligeiramente modificados.  Copiando\-os de OLE2. H pode reduzir os erros que são difíceis de resolver.  
  
### BEGIN\_INTERFACE\_MAP e END\_INTERFACE\_MAP — descrições de Macro  
  
```  
  
              BEGIN_INTERFACE_MAP(   
   theClass,  
   baseClass   
) END_INTERFACE_MAP  
```  
  
## Observações  
  
#### Parâmetros  
 `theClass`  
 A classe na qual o mapa de interface é seja definido  
  
 `baseClass`  
 A classe da qual `theClass` deriva.  
  
## Observações  
 O `BEGIN_INTERFACE_MAP` e `END_INTERFACE_MAP` macros são usadas no arquivo de implementação para realmente definir o mapa de interface.  Para cada interface implementada há uma ou mais `INTERFACE_PART` invocações de macro.  Para cada agregação, que usa a classe, há um `INTERFACE_AGGREGATE` invocação de macro.  
  
### INTERFACE\_PART — Descrição da Macro  
  
```  
  
              INTERFACE_PART(   
   theClass,  
   iid,   
   localClass   
)  
```  
  
## Observações  
  
#### Parâmetros  
 `theClass`  
 O nome da classe que contém o mapa de interface.  
  
 `iid`  
 O `IID` que deve ser mapeado para a classe incorporada.  
  
 `localClass`  
 O nome da classe local \(menos 'X'\).  
  
## Observações  
 Essa macro é usada entre o `BEGIN_INTERFACE_MAP` macro e `END_INTERFACE_MAP` macro para cada interface que seu objeto oferecerá suporte.  Permite que você mapeie uma IID para um membro da classe indicada por `theClass` e `localClass`.  'm\_x' será adicionada para o `localClass` automaticamente.  Observe que mais de um `IID` pode ser associada um único membro.  Isso é muito útil quando você estiver implementando apenas uma interface "mais derivados" e deseja fornecer todas as interfaces intermediárias.  Um bom exemplo disso é o `IOleInPlaceFrameWindow` interface.  Sua hierarquia tem esta aparência:  
  
```  
IUnknown  
    IOleWindow  
        IOleUIWindow  
            IOleInPlaceFrameWindow  
```  
  
 Se um objeto implementa `IOleInPlaceFrameWindow`, um cliente pode `QueryInterface` em qualquer uma dessas interfaces: `IOleUIWindow`, `IOleWindow`, ou [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509), além de "mais derivada" interface `IOleInPlaceFrameWindow` \(aquele realmente estiver implementando\).  Para lidar com isso, você pode usar mais de uma `INTERFACE_PART` macro para mapear cada interface base para o `IOleInPlaceFrameWindow` interface:  
  
 no arquivo de definição de classe:  
  
```  
BEGIN_INTERFACE_PART(CMyFrameWindow, IOleInPlaceFrameWindow)  
```  
  
 no arquivo de classe de implementação:  
  
```  
BEGIN_INTERFACE_MAP(CMyWnd, CFrameWnd)  
    INTERFACE_PART(CMyWnd, IID_IOleWindow, MyFrameWindow)  
    INTERFACE_PART(CMyWnd, IID_IOleUIWindow, MyFrameWindow)  
    INTERFACE_PART(CMyWnd, IID_IOleInPlaceFrameWindow, MyFrameWindow)  
END_INTERFACE_MAP  
```  
  
 A estrutura se encarrega de IUnknown porque sempre é necessária.  
  
### INTERFACE\_PART — Descrição da Macro  
  
```  
  
              INTERFACE_AGGREGATE(   
   theClass,  
   theAggr   
)  
```  
  
## Observações  
  
#### Parâmetros  
 `theClass`  
 O nome da classe que contém o mapa de interface,  
  
 `theAggr`  
 O nome da variável de membro que será agregado.  
  
## Observações  
 Essa macro é usada para informar a estrutura que a classe está usando um objeto de agregação.  Ele deve aparecer entre a `BEGIN_INTERFACE_PART` e `END_INTERFACE_PART` macros.  Um objeto de agregação é um objeto separado, derivado de [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509).  Usando uma agregação e o `INTERFACE_AGGREGATE` macro, você pode fazer todas as interfaces que o oferece suporte à agregação parecem ser suportado diretamente pelo objeto.  O `theAggr` é simplesmente o nome de uma variável de membro da classe que é derivada da [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) \(direta ou indiretamente\).  Todos os `INTERFACE_AGGREGATE` macros devem seguir o `INTERFACE_PART` macros quando colocado em um mapa de interface.  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)