---
title: 'TN039: Implementação de automação OLE MFC | Microsoft Docs'
ms.custom: ''
ms.date: 06/28/2018
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.mfc.ole
dev_langs:
- C++
helpviewer_keywords:
- MFC, COM support
- IDispatch interface
- MFC, OLE DB and
- TN039
- Automation, MFC COM interface entry points
ms.assetid: 765fa3e9-dd54-4f08-9ad2-26e0546ff8b6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9dcc179b1481c4f1f6b6a0773bba792eefffae25
ms.sourcegitcommit: 208d445fd7ea202de1d372d3f468e784e77bd666
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/29/2018
ms.locfileid: "37122115"
---
# <a name="tn039-mfcole-automation-implementation"></a>TN039: implementação de automação MFC/OLE

> [!NOTE]
> A Observação técnica a seguir não foi atualizada desde que ele foi incluído primeiro na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação on-line.

## <a name="overview-of-ole-idispatch-interface"></a>Visão geral da Interface de IDispatch OLE

O `IDispatch` interface é o meio pelo qual os aplicativos expõem métodos e propriedades, de modo que outros aplicativos, como Visual BASIC ou outras linguagens, podem fazer uso de recursos do aplicativo. É a parte mais importante desta interface de `IDispatch::Invoke` função. MFC usa "mapas de envios" implementar `IDispatch::Invoke`. O mapa de expedição fornece as informações de implementação do MFC de layout ou "forma" de seu `CCmdTarget`-classes derivadas, que ele diretamente pode manipular as propriedades do objeto ou chamar funções em seu objeto para atender de membro `IDispatch::Invoke` solicitações.

A maior parte, ClassWizard e MFC cooperam para ocultar a maioria dos detalhes de automação OLE do programador de aplicativo. O programador concentra-se na funcionalidade real para expor no aplicativo e não precisa se preocupar sobre a estrutura subjacente.

Há casos, no entanto, em que é necessário entender o que está fazendo MFC em segundo plano. Esta anotação abordará como o framework atribui **DISPID**s para funções de membro e propriedades. Conhecimento do algoritmo MFC usa para atribuir **DISPID**s só é necessária quando você precisa saber as IDs, como quando você cria uma biblioteca de tipos"" para objetos do aplicativo.

## <a name="mfc-dispid-assignment"></a>Atribuição de MFC DISPID

Embora o usuário final de automação (um Visual Basic usuário, por exemplo), verá os nomes reais de automação habilitado propriedades e métodos no código (como obj. ShowWindow), a implementação de `IDispatch::Invoke` não recebe os nomes reais. Por motivos de otimização, ele recebe um **DISPID**, que é 32-bit "magic cookie" que descreve o método ou propriedade a ser acessado. Essas **DISPID** retornado de valores de `IDispatch` implementação por outro método, chamado `IDispatch::GetIDsOfNames`. Um aplicativo de cliente de automação chamará `GetIDsOfNames` depois de cada membro ou propriedade que pretende acessar e armazenar em cache-los para chamadas posteriores para `IDispatch::Invoke`. Dessa forma, a pesquisa de cadeia de caracteres caro é realizada apenas uma vez por uso de objeto, em vez de uma vez por `IDispatch::Invoke` chamar.

MFC determina o **DISPID**s para cada propriedade e método com base em duas coisas:

- A distância da parte superior do mapa de expedição (1 relativo)

- A distância do mapa de expedição da classe mais derivado (0 relativo)

O **DISPID** é dividido em duas partes. O **LOWORD** do **DISPID** contém o primeiro componente, a distância da parte superior do mapa de expedição. O **HIWORD** contém a distância da classe mais derivada. Por exemplo:

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

Como você pode ver, há duas classes, que expõem interfaces de automação OLE. Uma dessas classes é derivada de outro e, portanto, aproveita a funcionalidade da classe base, incluindo a parte de automação OLE ("x" e "y" propriedades neste caso).

MFC gerará **DISPID**s para a classe CDispPoint da seguinte maneira:

```cpp
property X    (DISPID)0x00000001
property Y    (DISPID)0x00000002
```

Como as propriedades não estão em uma classe base, o **HIWORD** do **DISPID** é sempre zero (a distância entre a classe mais derivada de CDispPoint será zero).

MFC gerará **DISPID**s para a classe CDisp3DPoint da seguinte maneira:

```cpp
property Z    (DISPID)0x00000001
property X    (DISPID)0x00010001
property Y    (DISPID)0x00010002
```

A propriedade Z é fornecida um **DISPID** com um zero **HIWORD** desde que ele é definido na classe que está expondo propriedades, CDisp3DPoint. Como as propriedades X e Y são definidas em uma classe base, o **HIWORD** do **DISPID** é 1, uma vez que é a classe na qual essas propriedades são definidas em uma distância de uma derivação de classe mais derivada.

> [!NOTE]
> O **LOWORD** sempre é determinada pela posição no mapa, mesmo se não houver entradas no mapa com explícita **DISPID** (consulte a próxima seção para obter informações sobre o **ID** versões do `DISP_PROPERTY` e `DISP_FUNCTION` macros).

## <a name="advanced-mfc-dispatch-map-features"></a>Recursos de mapa de expedição MFC avançados

Há uma série de recursos adicionais que não oferece suporte a ClassWizard com esta versão do Visual C++. Oferece suporte a ClassWizard `DISP_FUNCTION`, `DISP_PROPERTY`, e `DISP_PROPERTY_EX` que definem um método, propriedade de variável de membro e propriedades de função de membro get/set, respectivamente. Esses recursos normalmente são tudo o que é necessário para criar a maioria dos servidores de automação.

As seguintes macros adicionais podem ser usadas quando as macros ClassWizard suportada não são adequadas: `DISP_PROPERTY_NOTIFY`, e `DISP_PROPERTY_PARAM`.

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

*theClass*  
 Nome da classe.

*pszName*  
 Nome externo da propriedade.

*nome do membro*  
 Nome da variável de membro no qual a propriedade é armazenada.

*pfnAfterSet*  
 Nome da função de membro para chamar quando a propriedade é alterada.

*vtPropType*  
 Um valor que especifica o tipo da propriedade.

### <a name="remarks"></a>Comentários

Essa macro é semelhante a DISP_PROPERTY, exceto que ele aceite um argumento adicional. O argumento adicional, *pfnAfterSet,* deve ser uma função de membro que não retorne nada e não usa nenhum parâmetro, 'void OnPropertyNotify()'. Ele será chamado **depois** a variável de membro tiver sido modificada.

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

*theClass*  
 Nome da classe.

*pszName*  
 Nome externo da propriedade.

*memberGet*  
 Nome da função de membro usada para obter a propriedade.

*conjunto de membros*  
 Nome da função de membro usada para definir a propriedade.

*vtPropType*  
 Um valor que especifica o tipo da propriedade.

*vtsParams*  
 Uma cadeia de caracteres de espaço separados VTS_ para cada parâmetro.

### <a name="remarks"></a>Comentários

Muito como a macro DISP_PROPERTY_EX, esta macro define uma propriedade acessada com funções de membro Get e Set separadas. Essa macro, no entanto, permite que você especifique uma lista de parâmetros para a propriedade. Isso é útil para implementar propriedades que são indexadas ou com parâmetros de alguma outra maneira. Os parâmetros serão sempre colocados primeiro, seguido pelo novo valor para a propriedade. Por exemplo:

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

*theClass*  
Nome da classe.

*pszName*  
Nome externo da propriedade.

*DISPID*  
O DISPID fixado para a propriedade ou método.

*pfnGet*  
Nome da função de membro usada para obter a propriedade.

*pfnSet*  
Nome da função de membro usada para definir a propriedade.

*nome do membro*  
O nome da variável de membro para mapear para a propriedade

*vtPropType*  
Um valor que especifica o tipo da propriedade.

*vtsParams*  
Uma cadeia de caracteres de espaço separados VTS_ para cada parâmetro.

### <a name="remarks"></a>Comentários

Essas macros permitem que você especifique um **DISPID** em vez de deixar o MFC automaticamente atribuir um. Essas avançadas macros têm os mesmos nomes, exceto o ID é acrescentado ao nome da macro (por exemplo, **DISP_PROPERTY_ID**) e a ID é determinada pelo parâmetro especificado logo após o *pszName* parâmetro. Consulte AFXDISP. H para obter mais informações sobre essas macros. O **ID** entradas devem ser colocadas no final do mapa de expedição. Elas afetam o automático **DISPID** geração da mesma maneira como não**ID** versão da macro seria (o **DISPID**s são determinadas pela posição). Por exemplo:

```cpp
BEGIN_DISPATCH_MAP(CDisp3DPoint, CCmdTarget)
    DISP_PROPERTY(CDisp3DPoint, "y", m_y, VT_I2)
    DISP_PROPERTY(CDisp3DPoint, "z", m_z, VT_I2)
    DISP_PROPERTY_ID(CDisp3DPoint, "x", 0x00020003, m_x, VT_I2)
END_DISPATCH_MAP()
```

MFC gerará DISPIDs para a classe CDisp3DPoint da seguinte maneira:

```cpp
property X    (DISPID)0x00020003
property Y    (DISPID)0x00000002
property Z    (DISPID)0x00000001
```

Especificando um fixa **DISPID** é útil para manter a compatibilidade com versões anteriores a uma interface de expedição já existente, ou para implementar determinadas propriedades ou métodos definidos pelo sistema (normalmente indicado por um negativo  **DISPID**, como o **DISPID_NEWENUM** coleção).

## <a name="retrieving-the-idispatch-interface-for-a-coleclientitem"></a>Recuperando a Interface IDispatch para um COleClientItem

Muitos servidores oferecerem suporte a automação dentro de seus objetos de documento, juntamente com a funcionalidade de servidor OLE. Para acessar essa interface de automação, é necessário para acessar diretamente o `COleClientItem::m_lpObject` variável de membro. O código a seguir recupera o `IDispatch` interface para um objeto derivado de `COleClientItem`. Você pode incluir o código abaixo em seu aplicativo, se você encontrar essa funcionalidade necessários:

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

A interface de Despache retornado dessa função pode ser usada diretamente ou anexada a um `COleDispatchDriver` para acesso fortemente tipado. Se você usá-lo diretamente, certifique-se de que você chame seu `Release` membro quando por meio de ponteiro (o `COleDispatchDriver` destruidor faz isso por padrão).

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)  
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)  
