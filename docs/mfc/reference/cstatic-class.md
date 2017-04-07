---
title: Classe CStatic | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CStatic
- AFXWIN/CStatic
- AFXWIN/CStatic::CStatic
- AFXWIN/CStatic::Create
- AFXWIN/CStatic::DrawItem
- AFXWIN/CStatic::GetBitmap
- AFXWIN/CStatic::GetCursor
- AFXWIN/CStatic::GetEnhMetaFile
- AFXWIN/CStatic::GetIcon
- AFXWIN/CStatic::SetBitmap
- AFXWIN/CStatic::SetCursor
- AFXWIN/CStatic::SetEnhMetaFile
- AFXWIN/CStatic::SetIcon
dev_langs:
- C++
helpviewer_keywords:
- enhanced metafiles
- cursors, displaying
- static controls
- controls [MFC], static
- icons, displaying
- CStatic class
- enhanced metafiles, displaying
- bitmaps, displaying
ms.assetid: e7c94cd9-5ebd-428a-aa30-b3e51f8efb95
caps.latest.revision: 21
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
ms.openlocfilehash: 0209fad1b84b782cdec7927cb5a04e9bb3083d64
ms.lasthandoff: 02/25/2017

---
# <a name="cstatic-class"></a>Classe CStatic
Fornece a funcionalidade de um controle estático do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CStatic : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CStatic::CStatic](#cstatic)|Constrói um objeto `CStatic`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CStatic::Create](#create)|Cria o controle estático do Windows e anexa-o para o `CStatic` objeto.|  
|[CStatic::DrawItem](#drawitem)|Substituição para desenhar um controle estático desenhados pelo proprietário.|  
|[CStatic::GetBitmap](#getbitmap)|Recupera o identificador do bitmap definido anteriormente com [SetBitmap](#setbitmap).|  
|[CStatic::GetCursor](#getcursor)|Recupera o identificador da imagem do cursor definido anteriormente com [SetCursor](#setcursor).|  
|[CStatic::GetEnhMetaFile](#getenhmetafile)|Recupera o identificador do metarquivo aprimorado definido anteriormente com [SetEnhMetaFile](#setenhmetafile).|  
|[CStatic::GetIcon](#geticon)|Recupera o identificador do ícone definido anteriormente com [SetIcon](#seticon).|  
|[CStatic::SetBitmap](#setbitmap)|Especifica um bitmap a ser exibido no controle estático.|  
|[CStatic::SetCursor](#setcursor)|Especifica uma imagem de cursor a ser exibido no controle estático.|  
|[CStatic::SetEnhMetaFile](#setenhmetafile)|Especifica um metarquivo avançado para ser exibido no controle estático.|  
|[CStatic::SetIcon](#seticon)|Especifica um ícone a ser exibido no controle estático.|  
  
## <a name="remarks"></a>Comentários  
 Um controle estático exibe uma cadeia de caracteres de texto, caixa, retângulo, ícone, cursor, bitmap ou metarquivo avançado. Ele pode ser usado para rotular, caixa ou separar outros controles. Normalmente, um controle estático não recebe nenhuma entrada e não fornece nenhuma saída; No entanto, ele pode notificar seu pai de cliques do mouse se ela for criada com **SS_NOTIFY** estilo.  
  
 Crie um controle estático em duas etapas. Primeiro, chame o construtor para construir o `CStatic` do objeto, em seguida, chame o [criar](#create) a função de membro para criar o controle estático e anexá-lo a `CStatic` objeto.  
  
 Se você criar um `CStatic` objeto dentro de uma caixa de diálogo (por meio de um recurso de caixa de diálogo), o `CStatic` objeto é destruído automaticamente quando o usuário fecha a caixa de diálogo.  
  
 Se você criar um `CStatic` do objeto em uma janela, você também precisa destruí-lo. Um `CStatic` criado na pilha dentro de uma janela de objeto é destruído automaticamente. Se você criar o `CStatic` objeto no heap usando o **novo** função, você deve chamar **excluir** no objeto para destruí-lo quando tiver terminado com ele.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CStatic`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="create"></a>CStatic::Create  
 Cria o controle estático do Windows e anexa-o para o `CStatic` objeto.  
  
```  
virtual BOOL Create(
    LPCTSTR lpszText,  
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID = 0xffff);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszText`  
 Especifica o texto para colocar no controle. Se **nulo**, nenhum texto ficará visível.  
  
 `dwStyle`  
 Especifica o estilo da janela do controle estático. Aplique qualquer combinação de [estilos de controle estático](../../mfc/reference/static-styles.md) ao controle.  
  
 `rect`  
 Especifica a posição e o tamanho do controle estático. Ele pode ser um `RECT` estrutura ou um `CRect` objeto.  
  
 `pParentWnd`  
 Especifica o `CStatic` janela pai, geralmente um `CDialog` objeto. Ele não deve ser **nulo**.  
  
 `nID`  
 Especifica a ID do controle. do controle estático  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Construir uma `CStatic` objeto em duas etapas. Primeiro, chame o construtor `CStatic`e, em seguida, chame **criar**, que cria o controle estático do Windows e anexa-o para o `CStatic` objeto.  
  
 Aplique o seguinte [estilos de janela](../../mfc/reference/window-styles.md) para um controle estático:  
  
- **Estilo** sempre  
  
- **WS_VISIBLE** geral  
  
- **WS_DISABLED** raramente  
  
 Se você pretende exibir um bitmap, cursor, ícone ou metarquivo no controle estático, você precisará aplicar um dos seguintes [estilos estáticos](../../mfc/reference/static-styles.md):  
  
- **SS_BITMAP** usar esse estilo de bitmaps.  
  
- **SS_ICON** usar esse estilo de ícones e cursores.  
  
- **SS_ENHMETAFILE** usar esse estilo para metarquivos.  
  
 Para cursores, bitmaps ou ícones, você talvez queira usar o estilo a seguir:  
  
- **SS_CENTERIMAGE** usar para centralizar a imagem no controle estático.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CStatic n º&1;](../../mfc/reference/codesnippet/cpp/cstatic-class_1.cpp)]  
  
##  <a name="cstatic"></a>CStatic::CStatic  
 Constrói um objeto `CStatic`.  
  
```  
CStatic();
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CStatic n º&2;](../../mfc/reference/codesnippet/cpp/cstatic-class_2.cpp)]  
  
##  <a name="drawitem"></a>CStatic::DrawItem  
 Chamado pela estrutura para desenhar um controle estático desenhados pelo proprietário.  
  
```  
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpDrawItemStruct`  
 Um ponteiro para um [DRAWITEMSTRUCT](../../mfc/reference/drawitemstruct-structure.md) estrutura. A estrutura contém informações sobre o item a ser desenhada e o tipo de desenho necessárias.  
  
### <a name="remarks"></a>Comentários  
 Substituir essa função para implementar o desenho de um desenho proprietário **CStatic** objeto (o controle tem o estilo **SS_OWNERDRAW**).  
  
##  <a name="getbitmap"></a>CStatic::GetBitmap  
 Obtém o identificador do bitmap, definido anteriormente com [SetBitmap](#setbitmap), que é associado com `CStatic`.  
  
```  
HBITMAP GetBitmap() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para o bitmap atual, ou **nulo** se nenhum bitmap tiver sido definido.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CStatic n º&3;](../../mfc/reference/codesnippet/cpp/cstatic-class_3.cpp)]  
  
##  <a name="getcursor"></a>CStatic::GetCursor  
 Obtém o identificador do cursor, definido anteriormente com [SetCursor](#setcursor), que é associado com `CStatic`.  
  
```  
HCURSOR GetCursor();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para o cursor atual, ou **nulo** se nenhum cursor tiver sido definido.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CStatic n º&4;](../../mfc/reference/codesnippet/cpp/cstatic-class_4.cpp)]  
  
##  <a name="getenhmetafile"></a>CStatic::GetEnhMetaFile  
 Obtém o identificador de metarquivo, definido anteriormente com [SetEnhMetafile](#setenhmetafile), que é associado com `CStatic`.  
  
```  
HENHMETAFILE GetEnhMetaFile() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para o metarquivo atual, ou **nulo** se nenhum Metarquivo Avançado foi definido.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CStatic n º&5;](../../mfc/reference/codesnippet/cpp/cstatic-class_5.cpp)]  
  
##  <a name="geticon"></a>CStatic::GetIcon  
 Obtém o identificador do ícone, definido anteriormente com [SetIcon](#seticon), que é associado com `CStatic`.  
  
```  
HICON GetIcon() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para o ícone atual, ou **nulo** se nenhum ícone tiver sido definido.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CStatic n º&6;](../../mfc/reference/codesnippet/cpp/cstatic-class_6.cpp)]  
  
##  <a name="setbitmap"></a>CStatic::SetBitmap  
 Associa um novo bitmap de controle estático.  
  
```  
HBITMAP SetBitmap(HBITMAP hBitmap);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hBitmap`  
 Identificador do bitmap a ser desenhado no controle estático.  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador do bitmap que foi previamente associado com o controle estático, ou `NULL` se nenhum bitmap foi associada ao controle estático.  
  
### <a name="remarks"></a>Comentários  
 O bitmap será desenhado automaticamente no controle estático. Por padrão, ela será desenhada no canto superior esquerdo e o controle estático será redimensionado para o tamanho do bitmap.  
  
 Você pode usar vários janela e estilos de controle estático, inclusive estas:  
  
-   SS_BITMAP usar esse estilo sempre para bitmaps.  
  
-   Use SS_CENTERIMAGE para centralizar a imagem no controle estático. Se a imagem for maior do que o controle estático, ele será recortado. Se for menor do que o controle estático, o espaço vazio ao redor da imagem será preenchido pela cor do pixel no canto superior esquerdo do bitmap.  
  
-   MFC fornece a classe `CBitmap`, que pode ser usada quando você tem mais com uma imagem de bitmap que simplesmente chamar o Win32 funcione `LoadBitmap`. `CBitmap`, que contém um tipo de objeto GDI, geralmente é usado em cooperação com `CStatic`, que é um `CWnd` classe que é usado para exibir um objeto gráfico como um controle estático.  
  
 `CImage`é uma classe ATL/MFC que permite mais fácil trabalhar com bitmaps independentes de dispositivo (DIB). Para obter mais informações, consulte [classe CImage](../../atl-mfc-shared/reference/cimage-class.md).  
  
-   Uso típico é dar `CStatic::SetBitmap` um objeto GDI que é retornado pelo operador HBITMAP de um `CBitmap` ou `CImage` objeto. O código para fazer isso se parece com a seguinte linha.  
  
```  
MyStaticControl.SetBitmap(HBITMAP(MyBitmap));
```  
O exemplo a seguir cria dois `CStatic` objetos no heap. Em seguida, carrega uma com um bitmap de sistema usando `CBitmap::LoadOEMBitmap` e a outra usa um arquivo `CImage::Load`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CStatic n º&3;](../../mfc/reference/codesnippet/cpp/cstatic-class_3.cpp)]  
  
##  <a name="setcursor"></a>CStatic::SetCursor  
 Associa uma nova imagem de cursor com o controle estático.  
  
```  
HCURSOR SetCursor(HCURSOR hCursor);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hCursor`  
 Identificador do cursor a ser desenhado no controle estático.  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador do cursor anteriormente associado ao controle estático, ou **nulo** se nenhum cursor foi associada ao controle estático.  
  
### <a name="remarks"></a>Comentários  
 O cursor será desenhado automaticamente no controle estático. Por padrão, ela será desenhada no canto superior esquerdo e o controle estático será redimensionado para o tamanho do cursor.  
  
 Você pode usar vários janela e estilos de controle estático, incluindo o seguinte:  
  
- **SS_ICON** usar esse estilo sempre para ícones e cursores.  
  
- **SS_CENTERIMAGE** uso para o Centro de controle estático. Se a imagem for maior do que o controle estático, ele será recortado. Se for menor do que o controle estático, o espaço vazio ao redor da imagem será preenchido com a cor de plano de fundo do controle estático.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CStatic n º&4;](../../mfc/reference/codesnippet/cpp/cstatic-class_4.cpp)]  
  
##  <a name="setenhmetafile"></a>CStatic::SetEnhMetaFile  
 Associa uma nova imagem de metarquivo avançado com o controle estático.  
  
```  
HENHMETAFILE SetEnhMetaFile(HENHMETAFILE hMetaFile);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hMetaFile`  
 Identificador do metarquivo aprimorado a ser desenhado no controle estático.  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador do metarquivo aprimorado anteriormente associado ao controle estático, ou **nulo** se nenhum Metarquivo Avançado foi associado ao controle estático.  
  
### <a name="remarks"></a>Comentários  
 O metarquivo avançado será desenhado automaticamente no controle estático. O metarquivo avançado é dimensionado para ajustar o tamanho do controle estático.  
  
 Você pode usar vários janela e estilos de controle estático, incluindo o seguinte:  
  
- **SS_ENHMETAFILE** usar esse estilo sempre para metarquivos.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CStatic n º&5;](../../mfc/reference/codesnippet/cpp/cstatic-class_5.cpp)]  
  
##  <a name="seticon"></a>CStatic::SetIcon  
 Associa uma nova imagem do ícone do controle estático.  
  
```  
HICON SetIcon(HICON hIcon);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hIcon`  
 Identificador do ícone a ser desenhado no controle estático.  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador do ícone anteriormente associado ao controle estático, ou **nulo** se nenhum ícone foi associada ao controle estático.  
  
### <a name="remarks"></a>Comentários  
 O ícone será desenhado automaticamente no controle estático. Por padrão, ela será desenhada no canto superior esquerdo e o controle estático será redimensionado para o tamanho do ícone.  
  
 Você pode usar vários janela e estilos de controle estático, incluindo o seguinte:  
  
- **SS_ICON** usar esse estilo sempre para ícones e cursores.  
  
- **SS_CENTERIMAGE** uso para o Centro de controle estático. Se a imagem for maior do que o controle estático, ele será recortado. Se for menor do que o controle estático, o espaço vazio ao redor da imagem será preenchido com a cor de plano de fundo do controle estático.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CStatic n º&6;](../../mfc/reference/codesnippet/cpp/cstatic-class_6.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Classe CButton](../../mfc/reference/cbutton-class.md)   
 [Classe CComboBox](../../mfc/reference/ccombobox-class.md)   
 [Classe CEdit](../../mfc/reference/cedit-class.md)   
 [Classe CListBox](../../mfc/reference/clistbox-class.md)   
 [Classe CScrollBar](../../mfc/reference/cscrollbar-class.md)   
 [Classe CDialog](../../mfc/reference/cdialog-class.md)

