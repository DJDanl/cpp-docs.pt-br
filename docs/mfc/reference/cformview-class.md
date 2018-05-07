---
title: Classe CFormView | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CFormView
- AFXEXT/CFormView
- AFXEXT/CFormView::CFormView
- AFXEXT/CFormView::IsInitDlgCompleted
dev_langs:
- C++
helpviewer_keywords:
- CFormView [MFC], CFormView
- CFormView [MFC], IsInitDlgCompleted
ms.assetid: a99ec313-36f0-4f28-9d2b-de11de14ac19
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3486285b7b6430e9cd6f0e4a936aa3341bd72e0f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cformview-class"></a>Classe CFormView
A classe base usada para modos de exibição de formulário.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CFormView : public CScrollView  
```  
  
## <a name="members"></a>Membros  
  
### <a name="protected-constructors"></a>Construtores Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFormView::CFormView](#cformview)|Constrói um objeto `CFormView`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFormView::IsInitDlgCompleted](#isinitdlgcompleted)|Usado para sincronização durante a inicialização.|  
  
## <a name="remarks"></a>Comentários  
 Um modo de exibição de formulário é essencialmente uma exibição que contém os controles. Esses controles são dispostos com base em um recurso de modelo de caixa de diálogo. Use `CFormView` se você quiser formulários no seu aplicativo. Esses modos de exibição oferecem suporte a rolagem, conforme necessário, usando o [CScrollView](../../mfc/reference/cscrollview-class.md) funcionalidade.  
  
 Quando você estiver [criando um aplicativo baseado em formulários](../../mfc/reference/creating-a-forms-based-mfc-application.md), você pode basear sua classe de exibição `CFormView`, tornando-o um aplicativo baseado em formulários.  
  
 Você também pode inserir novos [tópicos de formulário](../../mfc/form-views-mfc.md) em aplicativos com base em modo de exibição de documento. Mesmo que seu aplicativo não oferecia suporte inicialmente formulários, o Visual C++ adicionará esse suporte quando você insere um novo formulário.  
  
 O Assistente de aplicativo MFC e o comando Adicionar classe são os métodos preferidos para a criação de aplicativos baseados em formulários. Se você precisar criar um aplicativo baseado em formulários sem usar esses métodos, consulte [criando um aplicativo baseado em formulários](../../mfc/reference/creating-a-forms-based-mfc-application.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CView](../../mfc/reference/cview-class.md)  
  
 [CScrollView](../../mfc/reference/cscrollview-class.md)  
  
 `CFormView`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxext.h  
  
##  <a name="cformview"></a>  CFormView::CFormView  
 Constrói um objeto `CFormView`.  
  
```  
CFormView(LPCTSTR lpszTemplateName);  
CFormView(UINT nIDTemplate);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszTemplateName`  
 Contém uma cadeia de caracteres terminada em nulo que é o nome de um recurso de modelo de caixa de diálogo.  
  
 `nIDTemplate`  
 Contém o número de identificação de um recurso de modelo de caixa de diálogo.  
  
### <a name="remarks"></a>Comentários  
 Quando você cria um objeto de um tipo derivado de `CFormView`, chamar um dos construtores para criar o objeto de exibição e identificar o recurso de caixa de diálogo na qual a exibição é baseada. Você pode identificar os recursos por nome (passar uma cadeia de caracteres como o argumento para o construtor) ou por sua ID (um inteiro sem sinal, como o argumento de passagem).  
  
 Os controles de janela e filho de exibição de formulário não são criados até `CWnd::Create` é chamado. `CWnd::Create` é chamado pelo framework como parte do processo de criação documento e exibição, que é controlado pelo modelo de documento.  
  
> [!NOTE]
>  A classe derivada *deve* fornecer seu próprio construtor. No construtor, chamar o construtor, `CFormView::CFormView`, com o nome do recurso ou a ID como um argumento, como mostra a visão geral da classe anterior.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#90](../../mfc/codesnippet/cpp/cformview-class_1.h)]  
  
 [!code-cpp[NVC_MFCDocView#91](../../mfc/codesnippet/cpp/cformview-class_2.cpp)]  
  
##  <a name="isinitdlgcompleted"></a>  CFormView::IsInitDlgCompleted  
 Usada pelo MFC para garantir que a inicialização é concluída antes de executar outras operações.  
  
```  
BOOL IsInitDlgCompleted() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 True se a função de inicialização para essa caixa de diálogo foi concluída.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC SNAPVW](../../visual-cpp-samples.md)   
 [Exemplo MFC VIEWEX](../../visual-cpp-samples.md)   
 [Classe CScrollView](../../mfc/reference/cscrollview-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CDialog](../../mfc/reference/cdialog-class.md)   
 [Classe CScrollView](../../mfc/reference/cscrollview-class.md)
