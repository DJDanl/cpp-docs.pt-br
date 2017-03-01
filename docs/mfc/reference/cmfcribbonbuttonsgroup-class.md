---
title: Classe CMFCRibbonButtonsGroup | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCRibbonButtonsGroup
dev_langs:
- C++
helpviewer_keywords:
- CMFCRibbonButtonsGroup class
ms.assetid: b993d93e-fc1a-472f-a87f-1d7b7b499845
caps.latest.revision: 34
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 2d8909ca63bd1d9121e1126d46a08312521cc4ac
ms.lasthandoff: 02/25/2017

---
# <a name="cmfcribbonbuttonsgroup-class"></a>Classe CMFCRibbonButtonsGroup
O `CMFCRibbonButtonsGroup` classe permite organizar um conjunto de botões de faixa de opções em um grupo. Todos os botões no grupo estão diretamente adjacentes horizontalmente e entre em uma borda.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCRibbonButtonsGroup : public CMFCRibbonBaseElement  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonButtonsGroup::CMFCRibbonButtonsGroup](#cmfcribbonbuttonsgroup)|Constrói um objeto `CMFCRibbonButtonsGroup`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonButtonsGroup::AddButton](#addbutton)|Adiciona um botão a um grupo.|  
|[CMFCRibbonButtonsGroup::AddButtons](#addbuttons)|Adiciona uma lista de botões a um grupo.|  
|[CMFCRibbonButtonsGroup::GetButton](#getbutton)|Retorna um ponteiro para o botão que está localizado em um índice especificado.|  
|[CMFCRibbonButtonsGroup::GetCount](#getcount)|Retorna o número de botões no grupo.|  
|[CMFCRibbonButtonsGroup::GetImageSize](#getimagesize)|Retorna o tamanho da imagem das imagens normais no grupo de faixa de opções (substituições [CMFCRibbonBaseElement::GetImageSize](../../mfc/reference/cmfcribbonbaseelement-class.md#getimagesize).)|  
|[CMFCRibbonButtonsGroup::GetRegularSize](#getregularsize)|Retorna o tamanho normal do elemento de faixa de opções (substituições [CMFCRibbonBaseElement::GetRegularSize](../../mfc/reference/cmfcribbonbaseelement-class.md#getregularsize).)|  
|[CMFCRibbonButtonsGroup::HasImages](#hasimages)|Relatórios se o `CMFCRibbonButtonsGroup` objeto contém imagens da barra de ferramentas.|  
|[CMFCRibbonButtonsGroup::OnDrawImage](#ondrawimage)|Desenha a imagem apropriada para um botão especificada, dependendo se o botão é normal, realçado ou desativado.|  
|[CMFCRibbonButtonsGroup::RemoveAll](#removeall)|Remove todos os botões do `CMFCRibbonButtonsGroup` objeto.|  
|[CMFCRibbonButtonsGroup::SetImages](#setimages)|Atribui imagens ao grupo.|  
|[CMFCRibbonButtonsGroup::SetParentCategory](#setparentcategory)|Define o pai `CMFCRibbonCategory` do `CMFCRibbonButtonsGroup` objeto e todos os botões dentro dele (substituições [CMFCRibbonBaseElement::SetParentCategory](../../mfc/reference/cmfcribbonbaseelement-class.md#setparentcategory).)|  
  
## <a name="remarks"></a>Comentários  
 O grupo é derivado de [CMFCBaseRibbonElement](../../mfc/reference/cmfcribbonbaseelement-class.md) e pode ser manipulado como uma entidade única. Você pode posicionar o grupo em qualquer menu Painel ou pop-up.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar vários métodos no `CMFCRibbonButtonsGroup` classe. O exemplo mostra como construir um `CMFCRibbonButtonsGroup` do objeto, atribuir imagens para o grupo de botões de faixa de opções e adicionar um botão para o grupo de botões de faixa de opções. Este trecho de código é parte do [desenhar cliente de exemplo](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_DrawClient n º&2;](../../mfc/reference/codesnippet/cpp/cmfcribbonbuttonsgroup-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)  
  
 [CMFCRibbonButtonsGroup](../../mfc/reference/cmfcribbonbuttonsgroup-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxribbonbuttonsgroup.h  
  
##  <a name="a-nameaddbuttona--cmfcribbonbuttonsgroupaddbutton"></a><a name="addbutton"></a>CMFCRibbonButtonsGroup::AddButton  
 Adiciona um botão a um grupo.  
  
```  
void AddButton(CMFCRibbonBaseElement* pButton);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pButton`  
 Um ponteiro para um botão para adicionar.  
  
##  <a name="a-nameaddbuttonsa--cmfcribbonbuttonsgroupaddbuttons"></a><a name="addbuttons"></a>CMFCRibbonButtonsGroup::AddButtons  
 Adiciona uma lista de botões a um grupo.  
  
```  
void AddButtons(
    const CList<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>& lstButtons);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lstButtons`  
 Uma lista de ponteiros para os botões que você deseja adicionar.  
  
##  <a name="a-namecmfcribbonbuttonsgroupa--cmfcribbonbuttonsgroupcmfcribbonbuttonsgroup"></a><a name="cmfcribbonbuttonsgroup"></a>CMFCRibbonButtonsGroup::CMFCRibbonButtonsGroup  
 Constrói um objeto `CMFCRibbonButtonsGroup`.  
  
```  
CMFCRibbonButtonsGroup();
CMFCRibbonButtonsGroup(CMFCRibbonBaseElement* pButton);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pButton`  
 Especifica um botão para adicionar o recém-criado para `CMFCRibbonButtonsGroup` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetbuttona--cmfcribbonbuttonsgroupgetbutton"></a><a name="getbutton"></a>CMFCRibbonButtonsGroup::GetButton  
 Retorna um ponteiro para o botão que está localizado em um índice especificado.  
  
```  
CMFCRibbonBaseElement* GetButton(int i) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `i`  
 Um índice com base em zero de um botão para retornar.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o botão que está localizado no índice especificado. `NULL`Se o índice especificado está fora do intervalo.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetcounta--cmfcribbonbuttonsgroupgetcount"></a><a name="getcount"></a>CMFCRibbonButtonsGroup::GetCount  
 Retorna o número de botões no grupo.  
  
```  
int GetCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de botões do grupo.  
  
##  <a name="a-namegetimagesizea--cmfcribbonbuttonsgroupgetimagesize"></a><a name="getimagesize"></a>CMFCRibbonButtonsGroup::GetImageSize  
 Recupera o tamanho da imagem de origem do protegido `CMFCToolBarImages` membro `m_Images`.  
  
```  
const CSize GetImageSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o tamanho da imagem de origem das imagens da barra de ferramentas, se houver algum, ou um `CSize` de zero se não.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetregularsizea--cmfcribbonbuttonsgroupgetregularsize"></a><a name="getregularsize"></a>CMFCRibbonButtonsGroup::GetRegularSize  
 Recupera o tamanho máximo possível do elemento de grupo da faixa de opções.  
  
```  
virtual CSize GetRegularSize(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Ponteiro para o contexto de dispositivo do grupo da faixa de opções.  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namehasimagesa--cmfcribbonbuttonsgrouphasimages"></a><a name="hasimages"></a>CMFCRibbonButtonsGroup::HasImages  
 Relatórios se o `CMFCRibbonButtonsGroup` objeto contém imagens da barra de ferramentas.  
  
```  
BOOL HasImages() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se o protegido `CMFCToolBarImages` membro `m_Images` contém quaisquer imagens, ou falso se não.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameondrawimagea--cmfcribbonbuttonsgroupondrawimage"></a><a name="ondrawimage"></a>CMFCRibbonButtonsGroup::OnDrawImage  
 Desenha a imagem apropriada para um botão especificada, dependendo se o botão é normal, realçado ou desativado.  
  
```  
virtual void OnDrawImage(
    CDC* pDC,  
    CRect rectImage,  
    CMFCRibbonBaseElement* pButton,  
    int nImageIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Ponteiro para o contexto do `CMFCRibbonButtonsGroup` objeto.  
  
 [in] `rectImage`  
 O retângulo na qual desenhar a imagem.  
  
 [in] `pButton`  
 O botão para o qual desenhar a imagem.  
  
 [in] `nImageIndex`  
 O índice da imagem para desenhar no botão (em uma das matrizes três imagem botões normais, realçado ou desativado).  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameremovealla--cmfcribbonbuttonsgroupremoveall"></a><a name="removeall"></a>CMFCRibbonButtonsGroup::RemoveAll  
 Remove todos os botões do `CMFCRibbonButtonsGroup` objeto.  
  
```  
void RemoveAll();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetimagesa--cmfcribbonbuttonsgroupsetimages"></a><a name="setimages"></a>CMFCRibbonButtonsGroup::SetImages  
 Atribui imagens para o grupo de botões de faixa de opções.  
  
```  
void SetImages(
    CMFCToolBarImages* pImages,  
    CMFCToolBarImages* pHotImages,  
    CMFCToolBarImages* pDisabledImages);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pImages`  
 Imagens normais.  
  
 [in] `pHotImages`  
 Hot imagens.  
  
 [in] `pDisabledImages`  
 Imagens desabilitadas.  
  
### <a name="remarks"></a>Comentários  
 Chame `SetImages` antes de adicionar botões a um grupo. O número de imagens deve ser maior ou igual ao número de botões a serem adicionados ao grupo.  
  
> [!NOTE]
>  Hot imagens são imagens que são exibidas quando o usuário passar o mouse sobre o botão. Desabilitado imagens são imagens que são exibidas quando o botão é desabilitado.  
  
##  <a name="a-namesetparentcategorya--cmfcribbonbuttonsgroupsetparentcategory"></a><a name="setparentcategory"></a>CMFCRibbonButtonsGroup::SetParentCategory  
 Define o pai `CMFCRibbonCategory` do `CMFCRibbonButtonsGroup` objeto e todos os botões dentro dele.  
  
```  
virtual void SetParentCategory(CMFCRibbonCategory* pCategory);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pCategory`  
 Ponteiro para a categoria pai para definir (os grupos com guias em controles da faixa de opções são chamados de categorias).  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)

