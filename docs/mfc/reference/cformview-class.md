---
title: Classe CFormView | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CFormView
dev_langs:
- C++
helpviewer_keywords:
- views, containing controls
- CFormView class
- form views
ms.assetid: a99ec313-36f0-4f28-9d2b-de11de14ac19
caps.latest.revision: 23
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
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 82b38b04aa3cf2368d41ee20847c952c3082d4e4
ms.lasthandoff: 02/25/2017

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
 Um modo de exibição de formulário é essencialmente uma exibição que contém controles. Esses controles são dispostos em um recurso de modelo de caixa de diálogo. Use `CFormView` se quiser formulários em seu aplicativo. Esses modos de exibição oferecem suporte a rolagem, conforme necessário, usando o [CScrollView](../../mfc/reference/cscrollview-class.md) funcionalidade.  
  
 Quando você estiver [criando um aplicativo baseado em formulários](../../mfc/reference/creating-a-forms-based-mfc-application.md), você pode basear sua classe de exibição `CFormView`, tornando-um aplicativo baseado em formulários.  
  
 Você também pode inserir novos [formulário tópicos](../../mfc/form-views-mfc.md) em aplicativos com base na exibição de documento. Mesmo que seu aplicativo não aceitou inicialmente forms, Visual C++ adicionará esse suporte quando você insere um novo formulário.  
  
 O Assistente para aplicativo do MFC e o comando Add Class são os métodos preferenciais para a criação de aplicativos baseados em formulários. Se você precisar criar um aplicativo baseado em formulários sem usar esses métodos, consulte [criando um aplicativo baseado em formulários](../../mfc/reference/creating-a-forms-based-mfc-application.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CView](../../mfc/reference/cview-class.md)  
  
 [CScrollView](../../mfc/reference/cscrollview-class.md)  
  
 `CFormView`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxext.h  
  
##  <a name="a-namecformviewa--cformviewcformview"></a><a name="cformview"></a>CFormView::CFormView  
 Constrói um objeto `CFormView`.  
  
```  
CFormView(LPCTSTR lpszTemplateName);  
CFormView(UINT nIDTemplate);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszTemplateName`  
 Contém uma cadeia de caracteres terminada em nulo que é o nome de um recurso de modelo de diálogo.  
  
 `nIDTemplate`  
 Contém o número de identificação de um recurso de modelo de diálogo.  
  
### <a name="remarks"></a>Comentários  
 Quando você cria um objeto de um tipo derivado de `CFormView`, chamar um dos construtores para criar o objeto de exibição e identificar o recurso de caixa de diálogo na qual a exibição será baseada. Você pode identificar os recursos por nome (passar uma cadeia de caracteres como argumento para o construtor) ou pela sua ID (um inteiro não assinado como o argumento de passagem).  
  
 Os controles de janela e filho do modo de exibição de formulário não são criados até `CWnd::Create` é chamado. `CWnd::Create`é chamado pela estrutura como parte do processo de criação documento e exibição, que é controlado por modelo de documento.  
  
> [!NOTE]
>  Sua classe derivada *deve* fornecer seu próprio construtor. No construtor, invocar o construtor, `CFormView::CFormView`, com o nome do recurso ou ID como um argumento, como mostra a visão geral da classe anterior.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#90;](../../mfc/codesnippet/cpp/cformview-class_1.h)]  
  
 [!code-cpp[NVC_MFCDocView&#91;](../../mfc/codesnippet/cpp/cformview-class_2.cpp)]  
  
##  <a name="a-nameisinitdlgcompleteda--cformviewisinitdlgcompleted"></a><a name="isinitdlgcompleted"></a>CFormView::IsInitDlgCompleted  
 Usado pela MFC para garantir que a inicialização seja concluída antes de executar outras operações.  
  
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

