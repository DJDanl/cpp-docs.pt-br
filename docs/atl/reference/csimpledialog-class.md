---
title: Classe CsimpleDialog
ms.date: 11/04/2016
f1_keywords:
- CSimpleDialog
- ATLWIN/ATL::CSimpleDialog
- ATLWIN/ATL::CSimpleDialog::DoModal
helpviewer_keywords:
- CSimpleDialog class
- CSimpleDialog class, modal dialog boxes in ATL
- dialog boxes, modal
- modal dialog boxes, ATL
ms.assetid: 2ae65cc9-4f32-4168-aecd-200b4a480fdf
ms.openlocfilehash: 345372d71ad96a74bb0ae6dd7e89bdf0724cd822
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330821"
---
# <a name="csimpledialog-class"></a>Classe CsimpleDialog

Esta classe implementa uma caixa de diálogo modal básica.

## <a name="syntax"></a>Sintaxe

```
template <WORD t_wDlgTemplateID, BOOL t_bCenter = TRUE>
class CSimpleDialog : public CDialogImplBase
```

#### <a name="parameters"></a>Parâmetros

*t_wDlgTemplateID*

O ID de recurso de recurso do modelo de diálogo.

*t_bCenter*<br/>
TRUE se o objeto de diálogo estiver centrado na janela do proprietário; caso contrário, FALSO.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSimpleDialog::DoModal](#domodal)|Cria uma caixa de diálogo modal.|

## <a name="remarks"></a>Comentários

Implementa uma caixa de diálogo modal com funcionalidade básica. `CSimpleDialog`fornece suporte apenas para controles comuns do Windows. Para criar e exibir uma caixa de diálogo modal, crie uma instância dessa classe, fornecendo o nome de um modelo de recurso existente para a caixa de diálogo. O objeto da caixa de diálogo fecha quando o usuário clica em qualquer controle com um valor pré-definido (como IDOK ou IDCANCEL).

`CSimpleDialog`permite que você crie apenas caixas de diálogo modais. `CSimpleDialog`fornece o procedimento da caixa de diálogo, que usa o mapa de mensagem padrão para direcionar mensagens aos manipuladores apropriados.

Consulte [Implementando uma caixa de diálogo](../../atl/implementing-a-dialog-box.md) para obter mais informações.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CDialogImplBase`

`CSimpleDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="csimpledialogdomodal"></a><a name="domodal"></a>CSimpleDialog::DoModal

Invoca uma caixa de diálogo modal e retorna o resultado da caixa de diálogo quando feito.

```
INT_PTR DoModal(HWND hWndParent = ::GetActiveWindow());
```

### <a name="parameters"></a>Parâmetros

*Hwndparent*<br/>
Uma alça para o pai da caixa de diálogo. Se nenhum valor for fornecido, o pai será definido como a janela ativa atual.

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, o valor de devolução é o ID de recurso do controle que despediu a caixa de diálogo.

Se a função falhar, o valor de retorno será de -1. Para obter outras informações sobre o erro, chame `GetLastError`.

### <a name="remarks"></a>Comentários

Este método lida com toda a interação com o usuário enquanto a caixa de diálogo está ativa. É isso que torna a caixa de diálogo modal; ou seja, o usuário não pode interagir com outras janelas até que a caixa de diálogo esteja fechada.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
