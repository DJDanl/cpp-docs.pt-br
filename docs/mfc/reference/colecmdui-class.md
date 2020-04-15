---
title: Classe COleCmdUI
ms.date: 09/12/2018
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
ms.openlocfilehash: 1b7a6b21a3ad778b4a5ca345b1aaf42875810e4e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376273"
---
# <a name="colecmdui-class"></a>Classe COleCmdUI

Implementa um método para o MFC atualizar o estado `IOleCommandTarget`dos objetos de interface do usuário relacionados aos recursos orientados pelo aplicativo.

## <a name="syntax"></a>Sintaxe

```
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
|[COleCmdUI::Habilitar](#enable)|Define ou limpa o sinalizador de comando enable.|
|[COleCmdUI::SetCheck](#setcheck)|Define o estado de um comando de alternação on/off.|
|[COleCmdUI::SetText](#settext)|Retorna um nome de texto ou seqüência de status para um comando.|

## <a name="remarks"></a>Comentários

Em um aplicativo que não está habilitado para DocObjects, quando o usuário visualiza um menu no aplicativo, o MFC processa UPDATE_COMMAND_UI notificações. Cada notificação recebe um objeto [CCmdUI](../../mfc/reference/ccmdui-class.md) que pode ser manipulado para refletir o estado de um comando específico. No entanto, quando seu aplicativo está ativado para DocObjects, o MFC processa UPDATE_OLE_COMMAND_UI notificações e atribui `COleCmdUI` objetos.

`COleCmdUI`permite que um DocObject receba comandos que se originam na interface de usuário de seu contêiner (como FileNew, Open, Print e assim por diante), e permite que um contêiner receba comandos que se originam na interface de usuário do DocObject. Embora `IDispatch` possa ser usado para despachar os mesmos comandos, `IOleCommandTarget` fornece uma maneira mais simples de consultar e executar porque depende de um conjunto padrão de comandos, geralmente sem argumentos, e nenhuma informação de tipo está envolvida. `COleCmdUI`pode ser usado para ativar, atualizar e definir outras propriedades dos comandos de interface do usuário DocObject. Quando quiser invocar o comando, ligue para [COleServerDoc::OnExecOleCmd](../../mfc/reference/coleserverdoc-class.md#onexecolecmd).

Para obter mais informações sobre docObjects, consulte [CDocObjectServer](../../mfc/reference/cdocobjectserver-class.md) e [CDocObjectServerItem](../../mfc/reference/cdocobjectserveritem-class.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Ccmdui](../../mfc/reference/ccmdui-class.md)

`COleCmdUI`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdocobj.h

## <a name="colecmduicolecmdui"></a><a name="colecmdui"></a>COleCmdUI::COleCmdUI

Constrói um `COleCmdUI` objeto associado a um determinado comando de interface de usuário.

```
COleCmdUI(
    OLECMD* rgCmds,
    ULONG cCmds,
    const GUID* m_pGroup);
```

### <a name="parameters"></a>Parâmetros

*RGCmds*<br/>
Uma lista de comandos suportados associados ao GUID dado. A `OLECMD` estrutura associa comandos com bandeiras de comando.

*cCmds*<br/>
A contagem de comandos em *rgCmds*.

*pGroup*<br/>
Um ponteiro para um GUID que identifica um conjunto de comandos.

### <a name="remarks"></a>Comentários

O `COleCmdUI` objeto fornece uma interface programática para atualizar objetos de interface de usuário do DocObject, como itens de menu ou botões de barra de controle. Os objetos de interface do usuário podem ser ativados, `COleCmdUI` desativados, verificados e/ou limpos através do objeto.

## <a name="colecmduienable"></a><a name="enable"></a>COleCmdUI::Habilitar

Chame esta função para definir `COleCmdUI` o sinalizador de comando do objeto para OLECOMDF_ENABLED, que informa à interface que o comando está disponível e ativado, ou para limpar o sinalizador de comando.

```
virtual void Enable(BOOL bOn);
```

### <a name="parameters"></a>Parâmetros

*Bon*<br/>
Indica se o comando `COleCmdUI` associado ao objeto deve ser ativado ou desativado. Não zero habilita o comando; 0 desabilita o comando.

## <a name="colecmduisetcheck"></a><a name="setcheck"></a>COleCmdUI::SetCheck

Chame esta função para definir o estado de um comando de alterneção de liga/desliga.

```
virtual void SetCheck(int nCheck);
```

### <a name="parameters"></a>Parâmetros

*Ncheck*<br/>
Um valor determinando o estado para definir um comando de alternância de on/off. Os valores são:

|Valor|Descrição|
|-----------|-----------------|
|**1**|Adere ao comando.|
|**2**|Define o comando como indeterminado; o estado não pode ser determinado porque o atributo deste comando está em estados ligados e desligados na seleção relevante.|
|qualquer outro valor|Detona o comando.|

## <a name="colecmduisettext"></a><a name="settext"></a>COleCmdUI::SetText

Chame esta função para retornar um nome de texto ou seqüência de status para um comando.

```
virtual void SetText(LPCTSTR lpszText);
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
Um ponteiro para o texto a ser usado com o comando.

## <a name="see-also"></a>Confira também

[Classe CCmdUI](../../mfc/reference/ccmdui-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
