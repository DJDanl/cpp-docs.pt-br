---
title: Classe CBitmapButton | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CBitmapButton
dev_langs:
- C++
helpviewer_keywords:
- buttons, bitmap
- CBitmapButton class
- bitmaps, button controls
ms.assetid: 9ad6cb45-c3c4-4fb1-96d3-1fe3df7bbcfc
caps.latest.revision: 22
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
ms.sourcegitcommit: 0b07f6b12e178d8e324313ea3b0f6de9ae7420c9
ms.openlocfilehash: 16d39cb380b75e6dcef71dda01626f120d5c12fb
ms.lasthandoff: 02/25/2017

---
# <a name="cbitmapbutton-class"></a>Classe CBitmapButton
Cria controles de botão de pressão rotulados com imagens de bitmap em vez de texto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CBitmapButton : public CButton  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CBitmapButton::CBitmapButton](#cbitmapbutton)|Constrói um objeto `CBitmapButton`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CBitmapButton::AutoLoad](#autoload)|Associa um objeto de um botão em uma caixa de diálogo de `CBitmapButton` classe, carrega o bitmap(s) por nome e tamanhos de botão para ajustar o bitmap.|  
|[CBitmapButton::LoadBitmaps](#loadbitmaps)|Inicializa o objeto ao carregar um ou mais recursos de bitmap nomeado de arquivo de recurso do aplicativo e anexando os bitmaps ao objeto.|  
|[CBitmapButton::SizeToContent](#sizetocontent)|Dimensiona o botão para acomodar o bitmap.|  
  
## <a name="remarks"></a>Comentários  
 `CBitmapButton`objetos contêm até quatro bitmaps, que contêm imagens para os diferentes estados de um botão pode assumir: backup (ou normal), inativo (ou selecionada), foco e desativado. Somente o bitmap primeiro é necessário; os outros são opcionais.  
  
 Botão de bitmap imagens incluem a borda ao redor da imagem, bem como a própria imagem. A borda geralmente exerce uma função na exibição de estado do botão. Por exemplo, o bitmap para o estado de foco normalmente é como um para o estado, mas com um retângulo tracejado baixo-relevo de borda ou uma linha sólida espessa na borda. O bitmap para o estado desabilitado geralmente é semelhante a um para o estado, mas tem menor contraste (como uma seleção de menu esmaecido ou esmaecido).  
  
 Esses bitmaps podem ser de qualquer tamanho, mas são tratados como se fossem o mesmo tamanho que o bitmap para o estado.  
  
 Vários aplicativos exigem diferentes combinações de imagens de bitmap:  
  
|Acima|Abaixo|Focalizado|Disabled|Aplicativo|  
|--------|----------|-------------|--------------|-----------------|  
|×||||Bitmap|  
|×|×|||Botão sem **WS_TABSTOP** estilo|  
|×|×|×|×|Botão de caixa de diálogo com todos os estados|  
|×|×|×||Botão de caixa de diálogo com **WS_TABSTOP** estilo|  
  
 Ao criar um controle de botão de bitmap, definir o **BS_OWNERDRAW** estilos para especificar que o botão é desenhado pelo proprietário. Isso faz com que o Windows enviar o `WM_MEASUREITEM` e `WM_DRAWITEM` mensagens para o botão; a estrutura lida com essas mensagens e gerencia a aparência do botão para você.  
  
### <a name="to-create-a-bitmap-button-control-in-a-windows-client-area"></a>Para criar um controle de botão de bitmap na área cliente da janela  
  
1.  Crie um a quatro imagens bitmap do botão.  
  
2.  Construir o [CBitmapButton](#cbitmapbutton) objeto.  
  
3.  Chamar o [criar](../../mfc/reference/cbutton-class.md#create) função para criar o controle de botão do Windows e anexá-lo a `CBitmapButton` objeto.  
  
4.  Chamar o [LoadBitmaps](#loadbitmaps) a função de membro para carregar os recursos de bitmap depois que o botão de bitmap é construído.  
  
### <a name="to-include-a-bitmap-button-control-in-a-dialog-box"></a>Para incluir um controle de botão de bitmap em uma caixa de diálogo  
  
1.  Crie um a quatro imagens bitmap do botão.  
  
2.  Crie um modelo de caixa de diálogo com um botão de desenho proprietário posicionado onde você deseja que o botão de bitmap. Não importa o tamanho do botão no modelo.  
  
3.  Definir a legenda do botão como um valor como " **MYIMAGE**" e definir um símbolo do botão como **IDC_MYIMAGE**.  
  
4.  No script de recurso do aplicativo, dar a cada uma das imagens criadas para o botão de uma ID construída acrescentando uma das letras "U", "D", "F" ou "X" (para cima, para baixo, foco e desativado) para a cadeia de caracteres usada para a legenda do botão na etapa 3. Para a legenda do botão " **MYIMAGE**," por exemplo, as IDs seria " **MYIMAGEU**," " **MYIMAGED**," " **MYIMAGEF**," e " **MYIMAGEX**." Você **deve** especificar a ID dos bitmaps de aspas duplas. Caso contrário, o resource editor atribuirá um número inteiro para o recurso e MFC falhará ao carregar a imagem.  
  
5.  Na classe de caixa de diálogo do aplicativo (derivado de `CDialog`), adicione um `CBitmapButton` objeto de membro.  
  
6.  No `CDialog` do objeto [OnInitDialog](../../mfc/reference/cdialog-class.md#oninitdialog) rotina, chamada de `CBitmapButton` do objeto [AutoLoad](#autoload) funcionar, usando como parâmetros de ID do controle do botão e o `CDialog` do objeto **isso** ponteiro.  
  
 Se você deseja controlar mensagens de notificação do Windows, como **BN_CLICKED**, enviado por um controle de botão de bitmap para seu pai (normalmente uma classe derivada de **CDialog)**, adicionar à `CDialog`-derivado de função do membro de entrada e o manipulador de mensagens do objeto um mapa de mensagem para cada mensagem. As notificações enviadas por uma `CBitmapButton` objeto são iguais àquelas enviadas por uma [CButton](../../mfc/reference/cbutton-class.md) objeto.  
  
 A classe [CToolBar](../../mfc/reference/ctoolbar-class.md) adota uma abordagem diferente para os botões de bitmap.  
  
 Para obter mais informações sobre `CBitmapButton`, consulte [controles](../../mfc/controls-mfc.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CButton](../../mfc/reference/cbutton-class.md)  
  
 `CBitmapButton`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxext.h  
  
##  <a name="a-nameautoloada--cbitmapbuttonautoload"></a><a name="autoload"></a>CBitmapButton::AutoLoad  
 Associa um objeto de um botão em uma caixa de diálogo de `CBitmapButton` classe, carrega o bitmap(s) por nome e tamanhos de botão para ajustar o bitmap.  
  
```  
BOOL AutoLoad(
    UINT nID,  
    CWnd* pParent);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 ID do controle. do botão  
  
 `pParent`  
 Ponteiro para o objeto que possui o botão.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Use o `AutoLoad` funcione para inicializar um botão de desenho proprietário em uma caixa de diálogo como um botão de bitmap. Instruções para usar essa função estão nos comentários para a `CBitmapButton` classe.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCControlLadenDialog&#75;](../../mfc/codesnippet/cpp/cbitmapbutton-class_1.cpp)]  
  
##  <a name="a-namecbitmapbuttona--cbitmapbuttoncbitmapbutton"></a><a name="cbitmapbutton"></a>CBitmapButton::CBitmapButton  
 Cria um objeto `CBitmapButton`.  
  
```  
CBitmapButton();
```  
  
### <a name="remarks"></a>Comentários  
 Depois de criar o C++ `CBitmapButton` de objeto, chame [CButton::Create](../../mfc/reference/cbutton-class.md#create) para criar o controle de botão do Windows e anexá-lo a `CBitmapButton` objeto.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCControlLadenDialog&#57;](../../mfc/codesnippet/cpp/cbitmapbutton-class_2.cpp)]  
  
##  <a name="a-nameloadbitmapsa--cbitmapbuttonloadbitmaps"></a><a name="loadbitmaps"></a>CBitmapButton::LoadBitmaps  
 Use esta função quando quiser carregar imagens bitmap identificadas por seus nomes de recursos ou números de identificação, ou quando você não pode usar o `AutoLoad` funcionar porque, por exemplo, você está criando um botão de bitmap que não faz parte de uma caixa de diálogo.  
  
```  
BOOL LoadBitmaps(
    LPCTSTR lpszBitmapResource,  
    LPCTSTR lpszBitmapResourceSel = NULL,  
    LPCTSTR lpszBitmapResourceFocus = NULL,  
    LPCTSTR lpszBitmapResourceDisabled = NULL);

 
BOOL LoadBitmaps(
    UINT nIDBitmapResource,  
    UINT nIDBitmapResourceSel = 0,  
    UINT nIDBitmapResourceFocus = 0,  
    UINT nIDBitmapResourceDisabled = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszBitmapResource*  
 Aponta para a cadeia de caracteres terminada em nulo que contém o nome do bitmap para normal do botão um bitmap ou "backup" do estado. Necessário.  
  
 *lpszBitmapResourceSel*  
 Aponta para a cadeia de caracteres terminada em nulo que contém o nome do bitmap para um botão de bitmap está selecionado ou "estado pressionado". Pode ser **nulo**.  
  
 *lpszBitmapResourceFocus*  
 Aponta para a cadeia de caracteres terminada em nulo que contém o nome do bitmap para um botão de bitmap voltado para o estado. Pode ser **nulo**.  
  
 *lpszBitmapResourceDisabled*  
 Aponta para a cadeia de caracteres terminada em nulo que contém o nome do bitmap para um botão de bitmap estado desabilitado. Pode ser **nulo**.  
  
 *nIDBitmapResource*  
 Especifica o número de identificação de recurso do recurso de bitmap para normal do botão um bitmap ou "backup" do estado. Necessário.  
  
 *nIDBitmapResourceSel*  
 Especifica o número de identificação de recurso do recurso de bitmap para um botão de bitmap está selecionado ou "estado pressionado". Pode ser 0.  
  
 *nIDBitmapResourceFocus*  
 Especifica o número de identificação de recurso do recurso de bitmap para o estado de foco do botão um bitmap. Pode ser 0.  
  
 *nIDBitmapResourceDisabled*  
 Especifica o número de identificação de recurso do recurso de bitmap para o estado desabilitado do botão um bitmap. Pode ser 0.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCControlLadenDialog&#58;](../../mfc/codesnippet/cpp/cbitmapbutton-class_3.cpp)]  
  
##  <a name="a-namesizetocontenta--cbitmapbuttonsizetocontent"></a><a name="sizetocontent"></a>CBitmapButton::SizeToContent  
 Chame essa função para redimensionar um botão de bitmap para o tamanho do bitmap.  
  
```  
void SizeToContent();
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCControlLadenDialog&#59;](../../mfc/codesnippet/cpp/cbitmapbutton-class_4.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC CTRLTEST](../../visual-cpp-samples.md)   
 [Classe CButton](../../mfc/reference/cbutton-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)


