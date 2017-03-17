---
title: Classe CDragListBox | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
- drag list box [C++]
- dragging list items
- CDragListBox class
- Windows [C++], list boxes
- list boxes
ms.assetid: fee20b42-60ae-4aa9-83f9-5a3d9b96e33b
caps.latest.revision: 24
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 4fafe461008e3545243d693e0d9e34acd57163e0
ms.openlocfilehash: 3010fd9a363aa1ca1c946a6fe967a7ba415649d4
ms.lasthandoff: 02/25/2017

---
# <a name="cdraglistbox-class"></a>Classe CDragListBox
Além de fornecer a funcionalidade de uma caixa de lista do Windows, a `CDragListBox` classe permite que o usuário mova itens de caixa de lista, como nomes de arquivo, na caixa de listagem.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDragListBox : public CListBox  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDragListBox::CDragListBox](#cdraglistbox)|Constrói um objeto `CDragListBox`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDragListBox::BeginDrag](#begindrag)|Chamado pela estrutura quando inicia uma operação de arrastar.|  
|[CDragListBox::CancelDrag](#canceldrag)|Chamado pela estrutura quando uma operação de arrastar foi cancelada.|  
|[CDragListBox::Dragging](#dragging)|Chamado pela estrutura durante uma operação de arrastar.|  
|[CDragListBox::DrawInsert](#drawinsert)|Desenha o guia de inserção da caixa de listagem de arrastar.|  
|[CDragListBox::Dropped](#dropped)|Chamado pela estrutura depois que o item foi descartado.|  
|[CDragListBox::ItemFromPt](#itemfrompt)|Retorna as coordenadas do item que está sendo arrastado.|  
  
## <a name="remarks"></a>Comentários  
 Caixas de listagem com esse recurso permitem aos usuários solicitar os itens em uma lista de forma que é mais útil para eles. Por padrão, a caixa de listagem moverá o item para o novo local na lista. No entanto, `CDragListBox` objetos podem ser personalizados para copiar itens em vez de movê-los.  
  
 O controle de caixa de listagem associada a `CDragListBox` classe não deve ter o **LBS_SORT** ou **LBS_MULTIPLESELECT** estilo. Para obter uma descrição dos estilos de caixa de lista, consulte [estilos de caixa de listagem](../../mfc/reference/list-box-styles.md).  
  
 Para usar uma caixa de listagem de arrastar em uma caixa de diálogo existente do seu aplicativo, adicione um controle de caixa de listagem para o modelo de caixa de diálogo usando o editor de caixa de diálogo e, em seguida, atribuir uma variável de membro (categoria `Control` e o tipo de variável `CDragListBox`) correspondente para o controle de caixa de listagem em seu modelo de caixa de diálogo.  
  
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
 Chamado pela estrutura quando ocorre um evento que pode começar uma operação de arrastar, como pressionar o botão esquerdo do mouse.  
  
```  
virtual BOOL BeginDrag(CPoint pt);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pt`  
 A [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto que contém as coordenadas do item que está sendo arrastado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se arrastar for permitida, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função para controlar o que acontece quando começa uma operação de arrastar. A implementação padrão de captura do mouse e permanece no modo arrastar até que o usuário clica no botão esquerdo ou direito do mouse ou pressionar ESC, momento em que a operação de arrastar foi cancelada.  
  
##  <a name="canceldrag"></a>CDragListBox::CancelDrag  
 Chamado pela estrutura quando uma operação de arrastar foi cancelada.  
  
```  
virtual void CancelDrag(CPoint pt);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pt`  
 A [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto que contém as coordenadas do item que está sendo arrastado.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função para lidar com qualquer processamento especial para o controle de caixa de listagem.  
  
##  <a name="cdraglistbox"></a>CDragListBox::CDragListBox  
 Constrói um objeto `CDragListBox`.  
  
```  
CDragListBox();
```  
  
##  <a name="dragging"></a>CDragListBox::Dragging  
 Chamado pela estrutura quando um item de caixa de listagem está sendo arrastado dentro de `CDragListBox` objeto.  
  
```  
virtual UINT Dragging(CPoint pt);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pt`  
 A [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto que contém x e y tela coordenadas do cursor.  
  
### <a name="return-value"></a>Valor de retorno  
 A ID de recurso do cursor a ser exibido. Os seguintes valores são possíveis:  
  
- `DL_COPYCURSOR`Indica que o item será copiado.  
  
- `DL_MOVECURSOR`Indica que o item será movido.  
  
- `DL_STOPCURSOR`Indica que o destino de soltar atual não é aceitável.  
  
### <a name="remarks"></a>Comentários  
 Retorna o comportamento padrão `DL_MOVECURSOR`. Substitua essa função para fornecer funcionalidade adicional.  
  
##  <a name="drawinsert"></a>CDragListBox::DrawInsert  
 Chamado pela estrutura para desenhar o guia de inserção antes do item com índice indicado.  
  
```  
virtual void DrawInsert(int nItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nItem`  
 Índice baseado em zero do ponto de inserção.  
  
### <a name="remarks"></a>Comentários  
 Um valor de - 1 limpa o guia de inserção. Substitua essa função para modificar a aparência ou o comportamento do guia de inserção.  
  
##  <a name="dropped"></a>CDragListBox::Dropped  
 Chamado pela estrutura quando um item é removido em uma `CDragListBox` objeto.  
  
```  
virtual void Dropped(
    int nSrcIndex,  
    CPoint pt);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nSrcIndex*  
 Especifica o índice baseado em zero da cadeia de caracteres ignorado.  
  
 `pt`  
 A [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto que contém as coordenadas do local de depósito.  
  
### <a name="remarks"></a>Comentários  
 O comportamento padrão copia o item de caixa de listagem e seus dados para o novo local e, em seguida, exclui o item original. Substitua essa função para personalizar o comportamento padrão, como a habilitação de cópias dos itens de caixa de lista para ser arrastado para outros locais dentro da lista.  
  
##  <a name="itemfrompt"></a>CDragListBox::ItemFromPt  
 Chamada para essa função para recuperar o índice baseado em zero do item de caixa de listagem localizada em `pt`.  
  
```  
int ItemFromPt(
    CPoint pt,  
    BOOL bAutoScroll = TRUE) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pt`  
 A [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto contendo as coordenadas de um ponto dentro da caixa de lista.  
  
 *bAutoScroll*  
 Diferente de zero se a rolagem é permitida, caso contrário, 0.  
  
### <a name="return-value"></a>Valor de retorno  
 Índice baseado em zero do item da caixa de lista de arrastar.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC TSTCON](../../visual-cpp-samples.md)   
 [Classe CListBox](../../mfc/reference/clistbox-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CListBox](../../mfc/reference/clistbox-class.md)

