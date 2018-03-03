---
title: Classe CSimpleDialog | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CSimpleDialog
- ATLWIN/ATL::CSimpleDialog
- ATLWIN/ATL::CSimpleDialog::DoModal
dev_langs:
- C++
helpviewer_keywords:
- CSimpleDialog class
- CSimpleDialog class, modal dialog boxes in ATL
- dialog boxes, modal
- modal dialog boxes, ATL
ms.assetid: 2ae65cc9-4f32-4168-aecd-200b4a480fdf
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5e497d5f1646ab890b7dafa3e1fb7e1c711a8a09
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="csimpledialog-class"></a>Classe CSimpleDialog
Essa classe implementa uma caixa de diálogo modal básico.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <WORD t_wDlgTemplateID, BOOL t_bCenter = TRUE>  
class CSimpleDialog : public CDialogImplBase
```  
  
#### <a name="parameters"></a>Parâmetros  
 *t_wDlgTemplateID*  
  
 A ID de recurso do recurso de modelo de caixa de diálogo.  
  
 *t_bCenter*  
 **TRUE** se o objeto de caixa de diálogo é centralizado na janela do proprietário; caso contrário **FALSE**.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSimpleDialog::DoModal](#domodal)|Cria uma caixa de diálogo modal.|  
  
## <a name="remarks"></a>Comentários  
 Implementa uma caixa de diálogo modal com a funcionalidade básica. `CSimpleDialog`fornece suporte para controles comuns do Windows somente. Para criar e exibir uma caixa de diálogo modal, crie uma instância dessa classe, fornecendo o nome de um modelo de recurso existente para a caixa de diálogo. O objeto de caixa de diálogo é fechada quando o usuário clica em qualquer controle com um valor predefinido (por exemplo, IDOK ou IDCANCEL).  
  
 `CSimpleDialog`permite que você crie somente caixas de diálogo modal. `CSimpleDialog`fornece o procedimento de caixa de diálogo, que usa o mapa da mensagem padrão para direcionar as mensagens para os manipuladores apropriados.  
  
 Consulte [implementando uma caixa de diálogo](../../atl/implementing-a-dialog-box.md) para obter mais informações.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CDialogImplBase`  
  
 `CSimpleDialog`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  
  
##  <a name="domodal"></a>CSimpleDialog::DoModal  
 Invoca uma caixa de diálogo modal e retorna o resultado da caixa de diálogo quando terminar.  
  
```
INT_PTR DoModal(HWND hWndParent = ::GetActiveWindow());
```  
  
### <a name="parameters"></a>Parâmetros  
 `hWndParent`  
 Um identificador para o pai da caixa de diálogo. Se nenhum valor for fornecido, o pai é definido para a janela ativa atual.  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, o valor de retorno é a ID de recurso do controle que será descartada a caixa de diálogo.  
  
 Se a função falhar, o valor de retorno é -1. Para obter outras informações sobre o erro, chame `GetLastError`.  
  
### <a name="remarks"></a>Comentários  
 Este método trata todas as interações com o usuário enquanto a caixa de diálogo está ativa. Isso faz com que a caixa de diálogo modal; ou seja, o usuário não pode interagir com outras janelas até que a caixa de diálogo é fechada.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)
