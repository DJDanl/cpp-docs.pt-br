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
ms.openlocfilehash: 30caf7b42cf570a5dcd92d48817ef3743cf63811
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50677429"
---
# <a name="colecmdui-class"></a>Classe COleCmdUI

Implementa um método para MFC atualizar o estado dos objetos de interface do usuário relacionado ao `IOleCommandTarget`-controlado por recursos de seu aplicativo.

## <a name="syntax"></a>Sintaxe

```
class COleCmdUI : public CCmdUI
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleCmdUI::COleCmdUI](#colecmdui)|Constrói um objeto `COleCmdUI`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleCmdUI::Enable](#enable)|Define ou limpa o ativar o sinalizador de comando.|
|[COleCmdUI::SetCheck](#setcheck)|Define o estado de uma alternância de ativar/desativar comando.|
|[COleCmdUI::SetText](#settext)|Retorna uma cadeia de texto nome ou o status de um comando.|

## <a name="remarks"></a>Comentários

Em um aplicativo que não está habilitado para DocObjects, quando os modos de exibição do usuário um menu no aplicativo, MFC processa as notificações UPDATE_COMMAND_UI. Cada notificação é fornecida uma [CCmdUI](../../mfc/reference/ccmdui-class.md) objeto que pode ser manipulado para refletir o estado de um determinado comando. No entanto, quando seu aplicativo está habilitado para DocObjects, MFC processa as notificações de UPDATE_OLE_COMMAND_UI e atribui `COleCmdUI` objetos.

`COleCmdUI` permite que o DocObject receber comandos que se originam na interface do usuário do seu contêiner (por exemplo, FileNew, abrir, imprimir e assim por diante) e permite que um contêiner receber comandos que se originam na interface do usuário do DocObject. Embora `IDispatch` poderia ser usado para distribuir os mesmos comandos, `IOleCommandTarget` fornece uma maneira mais simples de consulta e execute porque ele se baseia em um conjunto padrão de comandos, normalmente sem argumentos, e nenhuma informação de tipo está envolvida. `COleCmdUI` pode ser usado para habilitar, atualizar e definir outras propriedades de DocObject comandos de interface do usuário. Quando você deseja invocar o comando, chame [COleServerDoc::OnExecOleCmd](../../mfc/reference/coleserverdoc-class.md#onexecolecmd).

Para obter mais informações sobre DocObjects, consulte [CDocObjectServer](../../mfc/reference/cdocobjectserver-class.md) e [CDocObjectServerItem](../../mfc/reference/cdocobjectserveritem-class.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CCmdUI](../../mfc/reference/ccmdui-class.md)

`COleCmdUI`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdocobj.h

##  <a name="colecmdui"></a>  COleCmdUI::COleCmdUI

Constrói um `COleCmdUI` objeto associado a um comando de interface de usuário específica.

```
COleCmdUI(
    OLECMD* rgCmds,
    ULONG cCmds,
    const GUID* m_pGroup);
```

### <a name="parameters"></a>Parâmetros

*rgCmds*<br/>
Uma lista de comandos com suporte associadas com o GUID especificado. O `OLECMD` estrutura associa comandos com sinalizadores de comando.

*cCmds*<br/>
A contagem de comandos *rgCmds*.

*pGroup*<br/>
Um ponteiro para um GUID que identifica um conjunto de comandos.

### <a name="remarks"></a>Comentários

O `COleCmdUI` objeto fornece uma interface programática para atualizar objetos de interface do usuário DocObject como itens de menu ou botões da barra de controle. Os objetos de interface do usuário podem ser habilitados, desabilitados, verificados, e/ou limpo por meio de `COleCmdUI` objeto.

##  <a name="enable"></a>  COleCmdUI::Enable

Chame essa função para definir o sinalizador de comando da `COleCmdUI` OLECOMDF_ENABLED, que informa a interface para o comando está disponível e habilitado, ou limpar o sinalizador de comando do objeto.

```
virtual void Enable(BOOL bOn);
```

### <a name="parameters"></a>Parâmetros

*bOn*<br/>
Indica se o comando associado a `COleCmdUI` objeto deve ser habilitado ou desabilitado. NonZero permite que o comando; 0 desabilita o comando.

##  <a name="setcheck"></a>  COleCmdUI::SetCheck

Chame essa função para definir o estado de uma alternância de ativar/desativar comando.

```
virtual void SetCheck(int nCheck);
```

### <a name="parameters"></a>Parâmetros

*nVerifique*<br/>
Um valor que determina o estado para definir uma alternância de ativar/desativar comando. Os valores são:

|Valor|Descrição|
|-----------|-----------------|
|**1**|Define o comando como ativado.|
|**2**|Define o comando como indeterminado; o estado não pode ser determinado porque o atributo desse comando é no dentro e fora dos Estados da seleção relevante.|
|qualquer outro valor|Define o comando como desativado.|

##  <a name="settext"></a>  COleCmdUI::SetText

Chame essa função para retornar uma cadeia de texto nome ou o status de um comando.

```
virtual void SetText(LPCTSTR lpszText);
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
Um ponteiro para o texto a ser usado com o comando.

## <a name="see-also"></a>Consulte também

[Classe CCmdUI](../../mfc/reference/ccmdui-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)

