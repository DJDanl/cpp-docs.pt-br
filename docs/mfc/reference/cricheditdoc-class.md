---
title: Classe CRichEditDoc | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CRichEditDoc
- AFXRICH/CRichEditDoc
- AFXRICH/CRichEditDoc::CreateClientItem
- AFXRICH/CRichEditDoc::GetStreamFormat
- AFXRICH/CRichEditDoc::GetView
- AFXRICH/CRichEditDoc::m_bRTF
dev_langs:
- C++
helpviewer_keywords:
- CRichEditDoc [MFC], CreateClientItem
- CRichEditDoc [MFC], GetStreamFormat
- CRichEditDoc [MFC], GetView
- CRichEditDoc [MFC], m_bRTF
ms.assetid: c936ec18-d516-49d4-b7fb-c9aa0229eddc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 23aacdfca1dbc958c16223d7d57cec39ef65267b
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43221795"
---
# <a name="cricheditdoc-class"></a>Classe CRichEditDoc
Com o [CRichEditView](../../mfc/reference/cricheditview-class.md) e [CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md), fornece a funcionalidade do controle de edição rica dentro do contexto da arquitetura de exibição de documento do MFC.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CRichEditDoc : public COleServerDoc  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRichEditDoc::CreateClientItem](#createclientitem)|Chamado para executar a limpeza do documento.|  
|[CRichEditDoc::GetStreamFormat](#getstreamformat)|Indica se o fluxo de entrada e saída devem incluir informações de formatação.|  
|[CRichEditDoc::GetView](#getview)|Recupera o asssociated [CRichEditView](../../mfc/reference/cricheditview-class.md) objeto.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[M_brtf](#m_brtf)|Indica se o fluxo de e/s deve incluir a formatação.|  
  
## <a name="remarks"></a>Comentários  
 Um "controle de edição rica" é uma janela na qual o usuário pode inserir e editar o texto. O texto pode ser atribuído caracteres e formatação de parágrafo e pode incluir objetos OLE incorporados. Controles de edição avançada fornecem uma interface de programação de formatação de texto. No entanto, um aplicativo deve implementar quaisquer componentes de interface do usuário necessários para tornar as operações de formatação disponíveis para o usuário.  
  
 `CRichEditView` mantém o texto e as características de formatação de texto. `CRichEditDoc` mantém a lista de itens de cliente que estão no modo de exibição. `CRichEditCntrItem` fornece acesso de lado do contêiner para os itens de cliente OLE.  
  
 Esse controle comum do Windows (e, portanto, o [CRichEditCtrl](../../mfc/reference/cricheditctrl-class.md) e as classes relacionadas) está disponível somente para programas executados no Windows 95/98 e Windows NT versões 3.51 e posterior.  
  
 Para obter um exemplo do uso de um documento de edição rica em um aplicativo MFC, consulte o [WORDPAD](../../visual-cpp-samples.md) aplicativo de exemplo.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CDocument](../../mfc/reference/cdocument-class.md)  
  
 [COleDocument](../../mfc/reference/coledocument-class.md)  
  
 [COleLinkingDoc](../../mfc/reference/colelinkingdoc-class.md)  
  
 [COleServerDoc](../../mfc/reference/coleserverdoc-class.md)  
  
 `CRichEditDoc`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrich.h  
  
##  <a name="createclientitem"></a>  CRichEditDoc::CreateClientItem  
 Chame essa função para criar um `CRichEditCntrItem` do objeto e adicioná-lo a este documento.  
  
```  
virtual CRichEditCntrItem* CreateClientItem(REOBJECT* preo = NULL) const = 0;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *preo*  
 Ponteiro para um [REOBJECT](/windows/desktop/api/richole/ns-richole-_reobject) estrutura que descreve um item OLE. O novo `CRichEditCntrItem` objeto é construído ao redor deste item OLE. Se *preo* for NULL, o novo item do cliente está vazio.  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma nova [CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md) objeto que foi adicionado a este documento.  
  
### <a name="remarks"></a>Comentários  
 Essa função não executa qualquer inicialização OLE.  
  
 Para obter mais informações, consulte o [REOBJECT](/windows/desktop/api/richole/ns-richole-_reobject) estrutura no SDK do Windows.  
  
##  <a name="getstreamformat"></a>  CRichEditDoc::GetStreamFormat  
 Chame essa função para determinar o formato de texto para o conteúdo da edição avançada de streaming.  
  
```  
int GetStreamFormat() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos seguintes sinalizadores:  
  
- SF_TEXT indica o controle de edição sofisticada não mantém informações de formatação.  
  
- SF_RTF indica o controle de edição sofisticada manter informações de formatação.  
  
### <a name="remarks"></a>Comentários  
 O valor de retorno se baseia a [m_bRTF](#m_brtf) membro de dados. Essa função retorna SF_RTF se `m_bRTF` for TRUE; caso contrário, SF_TEXT.  
  
##  <a name="getview"></a>  CRichEditDoc::GetView  
 Chame essa função para acessar o [CRichEditView](../../mfc/reference/cricheditview-class.md) objeto associado a este `CRichEditDoc` objeto.  
  
```  
virtual CRichEditView* GetView() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para o `CRichEditView` objeto associado ao documento.  
  
### <a name="remarks"></a>Comentários  
 O texto e informações de formatação estão contidos dentro de `CRichEditView` objeto. O `CRichEditDoc` objeto mantém os itens OLE para serialização. Deve haver apenas um `CRichEditView` para cada `CRichEditDoc`.  
  
##  <a name="m_brtf"></a>  M_brtf  
 Quando for verdadeiro, indica que [CRichEditCtrl::StreamIn](../../mfc/reference/cricheditctrl-class.md#streamin) e [CRichEditCtrl::StreamOut](../../mfc/reference/cricheditctrl-class.md#streamout) deve armazenar o parágrafo e características de formatação de caracteres.  
  
```  
BOOL m_bRTF;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC WORDPAD](../../visual-cpp-samples.md)   
 [Classe COleServerDoc](../../mfc/reference/coleserverdoc-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CRichEditView](../../mfc/reference/cricheditview-class.md)   
 [Classe CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md)   
 [Classe COleDocument](../../mfc/reference/coledocument-class.md)   
 [Classe CRichEditCtrl](../../mfc/reference/cricheditctrl-class.md)
