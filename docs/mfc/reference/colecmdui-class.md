---
title: Classe COleCmdUI
ms.date: 07/24/2020
f1_keywords:
- COleCmdUI
- AFXDOCOBJ/COleCmdUI
- AFXDOCOBJ/COleCmdUI::COleCmdUI
- AFXDOCOBJ/COleCmdUI::Enable
- AFXDOCOBJ/COleCmdUI::SetCheck
- AFXDOCOBJ/COleCmdUI::SetText
helpviewer_keywords:
- COleCmdUI [MFC], COleCmdUI
- COleCmdUI [MFC], Enable
- COleCmdUI [MFC], SetCheck
- COleCmdUI [MFC], SetText
ms.assetid: a2d5ce08-6657-45d3-8673-2a9f32d50eec
ms.openlocfilehash: c21d9b504656e6bba5ca693e57958743bb1b8309
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87233204"
---
# <a name="colecmdui-class"></a>Classe COleCmdUI

Implementa um método para que o MFC atualize o estado dos objetos da interface do usuário relacionados aos `IOleCommandTarget` recursos orientados de seu aplicativo.

## <a name="syntax"></a>Sintaxe

```cpp
class COleCmdUI : public CCmdUI
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleCmdUI::COleCmdUI](#colecmdui)|Constrói um objeto `COleCmdUI`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleCmdUI:: habilitar](#enable)|Define ou limpa o sinalizador de comando Enable.|
|[COleCmdUI:: SetCheck](#setcheck)|Define o estado de um comando de alternância liga/desliga.|
|[COleCmdUI:: SetText](#settext)|Retorna um nome de texto ou uma cadeia de caracteres de status para um comando.|

## <a name="remarks"></a>Comentários

Em um aplicativo que não está habilitado para DocObjects, quando o usuário exibe um menu no aplicativo, o MFC processa UPDATE_COMMAND_UI notificações. Cada notificação recebe um objeto [CCmdUI](../../mfc/reference/ccmdui-class.md) que pode ser manipulado para refletir o estado de um comando específico. No entanto, quando o aplicativo é habilitado para DocObjects, o MFC processa UPDATE_OLE_COMMAND_UI notificações e atribui `COleCmdUI` objetos.

`COleCmdUI`permite que um DocObject receba comandos originados na interface do usuário de seu contêiner (como FileNew, abrir, imprimir e assim por diante) e permite que um contêiner receba comandos originados na interface do usuário do DocObject. Embora `IDispatch` o possa ser usado para distribuir os mesmos comandos, o `IOleCommandTarget` fornece uma maneira mais simples de consultar e executar, pois ele depende de um conjunto padrão de comandos, normalmente sem argumentos, e nenhuma informação de tipo está envolvida. `COleCmdUI`pode ser usado para habilitar, atualizar e definir outras propriedades de comandos da interface do usuário do DocObject. Quando você quiser invocar o comando, chame [COleServerDoc:: OnExecOleCmd](../../mfc/reference/coleserverdoc-class.md#onexecolecmd).

Para obter mais informações sobre DocObjects, consulte [CDocObjectServer](../../mfc/reference/cdocobjectserver-class.md) e [CDocObjectServerItem](../../mfc/reference/cdocobjectserveritem-class.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CCmdUI](../../mfc/reference/ccmdui-class.md)

`COleCmdUI`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AfxDocOb. h

## <a name="colecmduicolecmdui"></a><a name="colecmdui"></a>COleCmdUI::COleCmdUI

Constrói um `COleCmdUI` objeto associado a um comando de interface de usuário específico.

```cpp
COleCmdUI(
    OLECMD* rgCmds,
    ULONG cCmds,
    const GUID* m_pGroup);
```

### <a name="parameters"></a>parâmetros

*rgCmds*<br/>
Uma lista de comandos com suporte associados ao GUID fornecido. A `OLECMD` estrutura associa comandos a sinalizadores de comando.

*cCmds*<br/>
A contagem de comandos no *rgCmds*.

*pGroup*<br/>
Um ponteiro para um GUID que identifica um conjunto de comandos.

### <a name="remarks"></a>Comentários

O `COleCmdUI` objeto fornece uma interface programática para atualizar objetos da interface do usuário do DocObject, como itens de menu ou botões da barra de controle. Os objetos da interface do usuário podem ser habilitados, desabilitados, marcados e/ou apagados por meio do `COleCmdUI` objeto.

## <a name="colecmduienable"></a><a name="enable"></a>COleCmdUI:: habilitar

Chame essa função para definir o sinalizador de comando do `COleCmdUI` objeto como OLECOMDF_ENABLED, que informa à interface que o comando está disponível e habilitado, ou para limpar o sinalizador de comando.

```cpp
virtual void Enable(BOOL bOn);
```

### <a name="parameters"></a>parâmetros

*Bno*<br/>
Indica se o comando associado ao `COleCmdUI` objeto deve ser habilitado ou desabilitado. Zero habilita o comando; 0 desabilita o comando.

## <a name="colecmduisetcheck"></a><a name="setcheck"></a>COleCmdUI:: SetCheck

Chame essa função para definir o estado de um comando de alternância liga/desliga.

```cpp
virtual void SetCheck(int nCheck);
```

### <a name="parameters"></a>parâmetros

*nVerifique*<br/>
Um valor que determina o estado para definir um comando de alternância liga/desliga. Os valores são:

|Valor|Descrição|
|-----------|-----------------|
|**1**|Define o comando como on.|
|**2**|Define o comando como indeterminado; o estado não pode ser determinado porque o atributo desse comando está nos Estados ligado e desligado na seleção relevante.|
|qualquer outro valor|Define o comando como off.|

## <a name="colecmduisettext"></a><a name="settext"></a>COleCmdUI:: SetText

Chame essa função para retornar um nome de texto ou uma cadeia de caracteres de status para um comando.

```cpp
virtual void SetText(LPCTSTR lpszText);
```

### <a name="parameters"></a>parâmetros

*lpszText*<br/>
Um ponteiro para o texto a ser usado com o comando.

## <a name="see-also"></a>Confira também

[Classe CCmdUI](../../mfc/reference/ccmdui-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)
