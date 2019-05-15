---
title: 'TN039: Implementação de automação OLE do MFC'
ms.date: 06/28/2018
helpviewer_keywords:
- MFC, COM support
- IDispatch interface
- MFC, OLE DB and
- TN039
- Automation, MFC COM interface entry points
ms.assetid: 765fa3e9-dd54-4f08-9ad2-26e0546ff8b6
ms.openlocfilehash: e71b3795396aa73135e8dac022182d4371bb19ac
ms.sourcegitcommit: 934cb53fa4cb59fea611bfeb9db110d8d6f7d165
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/14/2019
ms.locfileid: "65611248"
---
# <a name="tn039-mfcole-automation-implementation"></a>TN039: Implementação de automação MFC/OLE

> [!NOTE]
> A nota técnica a seguir não foi atualizada desde que foi incluído pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação online.

## <a name="overview-of-ole-idispatch-interface"></a>Visão geral da Interface de IDispatch OLE

O `IDispatch` interface é o meio pelo qual aplicativos expõem métodos e propriedades, de modo que outros aplicativos, como Visual BASIC ou outras linguagens, podem fazer uso de recursos do aplicativo. A parte mais importante dessa interface é o `IDispatch::Invoke` função. O MFC usa "mapas de envios" implementar `IDispatch::Invoke`. O mapa de expedição fornece as informações de implementação de MFC no layout ou "forma" de seu `CCmdTarget`-classes derivadas, que ele diretamente pode manipular as propriedades do objeto ou chamar funções dentro de seu objeto para satisfazer de membro `IDispatch::Invoke` solicitações.

Na maior parte, o ClassWizard e MFC cooperam para ocultar a maioria dos detalhes de automação OLE do programador de aplicativos. O programador concentra-se a funcionalidade real para expor no aplicativo e não precisa se preocupar sobre a estrutura subjacente.

Há casos, no entanto, em que é necessário entender o que está fazendo no MFC em segundo plano. Essa observação abordará como o framework atribui **DISPID**s para funções de membro e propriedades. Dados de conhecimento do algoritmo para atribuir o MFC usa **DISPID**s só é necessário quando você precisa conhecer as IDs, como quando você cria uma "biblioteca de tipos" para objetos do seu aplicativo.

## <a name="mfc-dispid-assignment"></a>Atribuição de MFC DISPID

Embora o usuário final de automação (um Visual Basic usuário, por exemplo), verá os nomes reais da automação habilitada propriedades e métodos em seu código (como obj. ShowWindow), a implementação de `IDispatch::Invoke` não receber os nomes reais. Por motivos de otimização, ele recebe um **DISPID**, que é de 32 bits "mágico cookie" que descreve o método ou propriedade que deve ser acessado. Eles **DISPID** valores são retornados da `IDispatch` implementação por meio de outro método, chamado `IDispatch::GetIDsOfNames`. Um aplicativo de cliente de automação chamará `GetIDsOfNames` depois de cada membro ou propriedade pretende acessar e armazenar em cache-los para chamadas posteriores para `IDispatch::Invoke`. Dessa forma, a pesquisa de cadeia de caracteres cara é feita apenas uma vez por uso de objeto, em vez de uma vez por `IDispatch::Invoke` chamar.

MFC determina o **DISPID**s para cada método e propriedade com base em duas coisas:

- A distância da parte superior do mapa de expedição (relativo ao 1)

- A distância do mapa de expedição da classe mais derivada (0 relativo)

O **DISPID** é dividida em duas partes. O **LOWORD** da **DISPID** contém o primeiro componente, a distância da parte superior do mapa de expedição. O **HIWORD** contém a distância entre a classe mais derivada. Por exemplo:

```cpp
class CDispPoint : public CCmdTarget
{
public:
    short m_x, m_y;
    // ...
    DECLARE_DISPATCH_MAP()
    // ...
};

class CDisp3DPoint : public CDispPoint
{
public:
    short m_z;
    // ...
    DECLARE_DISPATCH_MAP()
    // ...
};

BEGIN_DISPATCH_MAP(CDispPoint, CCmdTarget)
    DISP_PROPERTY(CDispPoint, "x", m_x, VT_I2)
    DISP_PROPERTY(CDispPoint, "y", m_y, VT_I2)
END_DISPATCH_MAP()

BEGIN_DISPATCH_MAP(CDisp3DPoint, CDispPoint)
    DISP_PROPERTY(CDisp3DPoint, "z", m_z, VT_I2)
END_DISPATCH_MAP()
```

Como você pode ver, há duas classes, que expõem interfaces de automação OLE. Uma dessas classes é derivada do outro e, portanto, aproveita a funcionalidade da classe base, incluindo a parte de automação OLE ("x" e "y" propriedades neste caso).

MFC gerará **DISPID**s para a classe CDispPoint da seguinte maneira:

```cpp
property X    (DISPID)0x00000001
property Y    (DISPID)0x00000002
```

Uma vez que as propriedades não estão em uma classe base, o **HIWORD** da **DISPID** é sempre zero (a distância entre a classe mais derivada para CDispPoint é zero).

MFC gerará **DISPID**s para a classe CDisp3DPoint da seguinte maneira:

```cpp
property Z    (DISPID)0x00000001
property X    (DISPID)0x00010001
property Y    (DISPID)0x00010002
```

A propriedade Z é fornecida uma **DISPID** com um zero **HIWORD** , pois ele é definido na classe que expõe as propriedades, CDisp3DPoint. Como as propriedades X e Y são definidas em uma classe base, o **HIWORD** da **DISPID** é 1, pois a classe na qual essas propriedades são definidas é a uma distância de uma derivação da classe mais derivada.

> [!NOTE]
> O **LOWORD** sempre é determinada pela posição no mapa, mesmo se existem entradas no mapa com explícitas **DISPID** (consulte a próxima seção para obter informações sobre a **ID** versões dos `DISP_PROPERTY` e `DISP_FUNCTION` macros).

## <a name="advanced-mfc-dispatch-map-features"></a>Recursos de mapa de expedição MFC avançados

Há uma série de recursos adicionais que não oferece suporte a ClassWizard com esta versão do Visual C++. Dá suporte a ClassWizard `DISP_FUNCTION`, `DISP_PROPERTY`, e `DISP_PROPERTY_EX` que definem um método, propriedade de variável de membro e propriedades de função de membro get/set, respectivamente. Esses recursos normalmente são tudo o que é necessário para criar a maioria dos servidores de automação.

As seguintes macros adicionais podem ser usadas quando as macros com suporte de ClassWizard não são adequadas: `DISP_PROPERTY_NOTIFY`, e `DISP_PROPERTY_PARAM`.

## <a name="disppropertynotify--macro-description"></a>DISP_PROPERTY_NOTIFY — Descrição da Macro

```cpp
DISP_PROPERTY_NOTIFY(
    theClass,
    pszName,
    memberName,
    pfnAfterSet,
    vtPropType)
```

### <a name="parameters"></a>Parâmetros

*theClass*<br/>
Nome da classe.

*pszName*<br/>
Nome externo da propriedade.

*memberName*<br/>
Nome da variável de membro no qual a propriedade é armazenada.

*pfnAfterSet*<br/>
Nome da função de membro ser chamada quando a propriedade é alterada.

*vtPropType*<br/>
Um valor que especifica o tipo da propriedade.

### <a name="remarks"></a>Comentários

Essa macro é muito semelhante DISP_PROPERTY, exceto que ela aceita um argumento adicional. O argumento adicional, *pfnAfterSet,* deve ser uma função de membro que não retorne nada e não usa nenhum parâmetro, 'void OnPropertyNotify()'. Ele será chamado **depois de** a variável de membro tiver sido modificada.

## <a name="disppropertyparam--macro-description"></a>DISP_PROPERTY_PARAM — Descrição da Macro

```cpp
DISP_PROPERTY_PARAM(
    theClass,
    pszName,
    pfnGet,
    pfnSet,
    vtPropType,
    vtsParams)
```

### <a name="parameters"></a>Parâmetros

*theClass*<br/>
Nome da classe.

*pszName*<br/>
Nome externo da propriedade.

*memberGet*<br/>
Nome da função de membro usada para obter a propriedade.

*memberSet*<br/>
Nome da função de membro usada para definir a propriedade.

*vtPropType*<br/>
Um valor que especifica o tipo da propriedade.

*vtsParams*<br/>
Uma cadeia de caracteres de espaço separados VTS_ para cada parâmetro.

### <a name="remarks"></a>Comentários

Muito como a macro DISP_PROPERTY_EX, esta macro define uma propriedade acessada com funções de membro Get e Set separadas. Essa macro, no entanto, permite que você especifique uma lista de parâmetros para a propriedade. Isso é útil para implementar propriedades que são indexadas ou com parâmetros de alguma outra forma. Os parâmetros sempre sejam colocados em primeiro lugar, seguido pelo novo valor para a propriedade. Por exemplo:

```cpp
DISP_PROPERTY_PARAM(CMyObject, "item", GetItem, SetItem, VT_DISPATCH, VTS_I2 VTS_I2)
```

corresponderia para obter e definir funções de membro:

```cpp
LPDISPATCH CMyObject::GetItem(short row, short col)
void CMyObject::SetItem(short row, short col, LPDISPATCH newValue)
```

## <a name="dispxxxxid--macro-descriptions"></a>DISP_XXXX_ID — Descrições de Macro

```cpp
DISP_FUNCTION_ID(
    theClass,
    pszName,
    dispid,
    pfnMember,
    vtRetVal,
    vtsParams)
DISP_PROPERTY_ID(
    theClass,
    pszName,
    dispid,
    memberName,
    vtPropType)
DISP_PROPERTY_NOTIFY_ID(
    theClass,
    pszName,
    dispid,
    memberName,
    pfnAfterSet,
    vtPropType)
DISP_PROPERTY_EX_ID(
    theClass,
    pszName,
    dispid,
    pfnGet,
    pfnSet,
    vtPropType)
DISP_PROPERTY_PARAM_ID(
    theClass,
    pszName,
    dispid,
    pfnGet,
    pfnSet,
    vtPropType,
    vtsParams)
```

### <a name="parameters"></a>Parâmetros

*theClass*<br/>
Nome da classe.

*pszName*<br/>
Nome externo da propriedade.

*dispid*<br/>
O DISPID fixo para a propriedade ou método.

*pfnGet*<br/>
Nome da função de membro usada para obter a propriedade.

*pfnSet*<br/>
Nome da função de membro usada para definir a propriedade.

*memberName*<br/>
O nome da variável de membro para mapear para a propriedade

*vtPropType*<br/>
Um valor que especifica o tipo da propriedade.

*vtsParams*<br/>
Uma cadeia de caracteres de espaço separados VTS_ para cada parâmetro.

### <a name="remarks"></a>Comentários

Essas macros permitem que você especifique um **DISPID** em vez de deixar o MFC automaticamente atribuir um. Essas avançadas macros têm os mesmos nomes, exceto pelo fato de que o ID é acrescentado ao nome da macro (por exemplo, **DISP_PROPERTY_ID**) e a ID é determinada pelo parâmetro especificado logo após o *pszName* parâmetro. Consulte AFXDISP. H para obter mais informações sobre essas macros. O **ID** entradas devem ser colocadas no final do mapa de expedição. Elas afetarão o automático **DISPID** geração da mesma forma como um não -**ID** seria de versão da macro (o **DISPID**s são determinados pela posição). Por exemplo:

```cpp
BEGIN_DISPATCH_MAP(CDisp3DPoint, CCmdTarget)
    DISP_PROPERTY(CDisp3DPoint, "y", m_y, VT_I2)
    DISP_PROPERTY(CDisp3DPoint, "z", m_z, VT_I2)
    DISP_PROPERTY_ID(CDisp3DPoint, "x", 0x00020003, m_x, VT_I2)
END_DISPATCH_MAP()
```

MFC gerará os DISPIDs para classe CDisp3DPoint da seguinte maneira:

```cpp
property X    (DISPID)0x00020003
property Y    (DISPID)0x00000002
property Z    (DISPID)0x00000001
```

Especificando um fixo **DISPID** é útil para manter a compatibilidade com versões anteriores a uma interface de expedição anteriormente existentes, ou para implementar determinadas propriedades ou métodos definidos pelo sistema (geralmente, indicado por um negativo  **DISPID**, como o **DISPID_NEWENUM** coleção).

## <a name="retrieving-the-idispatch-interface-for-a-coleclientitem"></a>Recuperando a Interface IDispatch para um COleClientItem

Muitos servidores oferecerá suporte a automação de dentro de seus objetos de documento, juntamente com a funcionalidade de servidor OLE. Para obter acesso a esta interface de automação, é necessário para acessar diretamente o `COleClientItem::m_lpObject` variável de membro. O código a seguir recuperará o `IDispatch` para um objeto derivado da interface `COleClientItem`. Você pode incluir o código a seguir em seu aplicativo se você encontrar essa funcionalidade necessários:

```cpp
LPDISPATCH CMyClientItem::GetIDispatch()
{
    ASSERT_VALID(this);
    ASSERT(m_lpObject != NULL);

    LPUNKNOWN lpUnk = m_lpObject;

    Run();      // must be running

    LPOLELINK lpOleLink = NULL;
    if (m_lpObject->QueryInterface(IID_IOleLink,
        (LPVOID FAR*)&lpOleLink) == NOERROR)
    {
        ASSERT(lpOleLink != NULL);
        lpUnk = NULL;
        if (lpOleLink->GetBoundSource(&lpUnk) != NOERROR)
        {
            TRACE0("Warning: Link is not connected!\n");
            lpOleLink->Release();
            return NULL;
        }
        ASSERT(lpUnk != NULL);
    }

    LPDISPATCH lpDispatch = NULL;
    if (lpUnk->QueryInterface(IID_IDispatch, &lpDispatch) != NOERROR)
    {
        TRACE0("Warning: does not support IDispatch!\n");
        return NULL;
    }

    ASSERT(lpDispatch != NULL);
    return lpDispatch;
}
```

A interface de expedição retornado dessa função pode ser usada diretamente ou anexada a um `COleDispatchDriver` para acesso fortemente tipado. Se você usá-lo diretamente, certifique-se de que você chame seus `Release` membro quando por meio com o ponteiro (o `COleDispatchDriver` destruidor faz isso por padrão).

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
