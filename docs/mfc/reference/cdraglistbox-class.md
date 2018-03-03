---
title: Classe CDragListBox | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDragListBox
- AFXCMN/CDragListBox
- AFXCMN/CDragListBox::CDragListBox
- AFXCMN/CDragListBox::BeginDrag
- AFXCMN/CDragListBox::CancelDrag
- AFXCMN/CDragListBox::Dragging
- AFXCMN/CDragListBox::DrawInsert
- AFXCMN/CDragListBox::Dropped
- AFXCMN/CDragListBox::ItemFromPt
dev_langs:
- C++
helpviewer_keywords:
- CDragListBox [MFC], CDragListBox
- CDragListBox [MFC], BeginDrag
- CDragListBox [MFC], CancelDrag
- CDragListBox [MFC], Dragging
- CDragListBox [MFC], DrawInsert
- CDragListBox [MFC], Dropped
- CDragListBox [MFC], ItemFromPt
ms.assetid: fee20b42-60ae-4aa9-83f9-5a3d9b96e33b
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 424d9db088aa171bdbca868326eb80144a10704b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cdraglistbox-class"></a>Classe CDragListBox
Além de fornecer a funcionalidade de uma caixa de lista do Windows, o `CDragListBox` classe permite que o usuário mover itens da caixa de lista, como nomes de arquivo, na caixa de listagem.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDragListBox : public CListBox  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDragListBox::CDragListBox](#cdraglistbox)|Constrói um objeto `CDragListBox`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDragListBox::BeginDrag](#begindrag)|Chamado pelo framework quando uma operação de arrastar inicia.|  
|[CDragListBox::CancelDrag](#canceldrag)|Chamado pelo framework quando uma operação de arrastar foi cancelada.|  
|[CDragListBox::Dragging](#dragging)|Chamado pelo framework durante uma operação de arrastar.|  
|[CDragListBox::DrawInsert](#drawinsert)|Desenha o guia de inserção da caixa de listagem de arrastar.|  
|[CDragListBox::Dropped](#dropped)|Chamado pelo framework depois que o item foi descartado.|  
|[CDragListBox::ItemFromPt](#itemfrompt)|Retorna as coordenadas do item que está sendo arrastado.|  
  
## <a name="remarks"></a>Comentários  
 Caixas de listagem com esse recurso permitem aos usuários classificar os itens em uma lista de forma que é mais útil para eles. Por padrão, a caixa de listagem moverá o item para o novo local na lista. No entanto, `CDragListBox` objetos podem ser personalizados para copiar itens em vez de movê-los.  
  
 O controle de lista associado a `CDragListBox` classe não deve ter o **LBS_SORT** ou **LBS_MULTIPLESELECT** estilo. Para obter uma descrição dos estilos de caixa de lista, consulte [estilos de caixa de listagem](../../mfc/reference/styles-used-by-mfc.md#list-box-styles).  
  
 Para usar uma caixa de listagem de arrastar em uma caixa de diálogo existente do seu aplicativo, adicione um controle de caixa de listagem para o modelo de caixa de diálogo usando o editor de caixa de diálogo e, em seguida, atribuir uma variável de membro (categoria `Control` e o tipo de variável `CDragListBox`) correspondente à caixa de listagem o modelo de caixa de diálogo de controle.  
  
 Para obter mais informações sobre como atribuir controles a variáveis de membro, consulte [atalho para definir variáveis de membro para controles de caixa de diálogo](../../windows/defining-member-variables-for-dialog-controls.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CListBox](../../mfc/reference/clistbox-class.md)  
  
 `CDragListBox`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcmn.h  
  
##  <a name="begindrag"></a>CDragListBox::BeginDrag  
 Chamado pelo framework quando ocorre um evento que pode começar uma operação de arrastar, como pressionar o botão esquerdo do mouse.  
  
```  
virtual BOOL BeginDrag(CPoint pt);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pt`  
 Um [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto que contém as coordenadas do item que está sendo arrastado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se arrastando for permitida, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função se você deseja controlar o que acontece quando uma operação de arrastar inicia. A implementação padrão de captura o mouse e permanece em modo de arraste até que o usuário clica no botão esquerdo ou direito do mouse ou pressiona ESC, momento em que a operação de arrastar seja cancelada.  
  
##  <a name="canceldrag"></a>CDragListBox::CancelDrag  
 Chamado pelo framework quando uma operação de arrastar foi cancelada.  
  
```  
virtual void CancelDrag(CPoint pt);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pt`  
 Um [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto que contém as coordenadas do item que está sendo arrastado.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função para manipular qualquer processamento especial para o controle de caixa de listagem.  
  
##  <a name="cdraglistbox"></a>CDragListBox::CDragListBox  
 Constrói um objeto `CDragListBox`.  
  
```  
CDragListBox();
```  
  
##  <a name="dragging"></a>CDragListBox::Dragging  
 Chamado pelo framework quando um item de caixa de listagem é arrastado dentro de `CDragListBox` objeto.  
  
```  
virtual UINT Dragging(CPoint pt);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pt`  
 Um [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto que contém x e y tela coordenadas do cursor.  
  
### <a name="return-value"></a>Valor de retorno  
 A ID de recurso do cursor a ser exibido. Os seguintes valores são possíveis:  
  
- `DL_COPYCURSOR`Indica que o item será copiado.  
  
- `DL_MOVECURSOR`Indica que o item será movido.  
  
- `DL_STOPCURSOR`Indica que o destino atual não é aceitável.  
  
### <a name="remarks"></a>Comentários  
 Retorna o comportamento padrão `DL_MOVECURSOR`. Substitua essa função se desejar fornecer funcionalidade adicional.  
  
##  <a name="drawinsert"></a>CDragListBox::DrawInsert  
 Chamado pelo framework para desenhar o guia de inserção antes do item com índice indicado.  
  
```  
virtual void DrawInsert(int nItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nItem`  
 Índice de base zero do ponto de inserção.  
  
### <a name="remarks"></a>Comentários  
 Um valor de - 1 limpa o guia de inserção. Substitua essa função para modificar a aparência ou o comportamento do guia de inserção.  
  
##  <a name="dropped"></a>CDragListBox::Dropped  
 Chamado pelo framework quando um item é removido em uma `CDragListBox` objeto.  
  
```  
virtual void Dropped(
    int nSrcIndex,  
    CPoint pt);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nSrcIndex*  
 Especifica o índice de base zero da cadeia de caracteres descartada.  
  
 `pt`  
 Um [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto que contém as coordenadas do site drop.  
  
### <a name="remarks"></a>Comentários  
 O comportamento padrão copia o item de caixa de listagem e seus dados para o novo local e, em seguida, exclui o item original. Substitua essa função para personalizar o comportamento padrão, como a habilitação de cópias dos itens de caixa de lista para ser arrastado para outros locais dentro da lista.  
  
##  <a name="itemfrompt"></a>CDragListBox::ItemFromPt  
 Chamada para essa função para recuperar o índice com base em zero do item de caixa de listagem localizada em `pt`.  
  
```  
int ItemFromPt(
    CPoint pt,  
    BOOL bAutoScroll = TRUE) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pt`  
 Um [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto que contém as coordenadas de um ponto dentro da caixa de lista.  
  
 *bAutoScroll*  
 Diferente de zero se a rolagem é permitida, caso contrário, 0.  
  
### <a name="return-value"></a>Valor de retorno  
 Índice de base zero do item da caixa de lista de arrastar.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC TSTCON](../../visual-cpp-samples.md)   
 [Classe CListBox](../../mfc/reference/clistbox-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CListBox](../../mfc/reference/clistbox-class.md)
