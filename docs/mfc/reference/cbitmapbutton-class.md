---
title: Classe CBitmapButton | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CBitmapButton
- AFXEXT/CBitmapButton
- AFXEXT/CBitmapButton::CBitmapButton
- AFXEXT/CBitmapButton::AutoLoad
- AFXEXT/CBitmapButton::LoadBitmaps
- AFXEXT/CBitmapButton::SizeToContent
dev_langs:
- C++
helpviewer_keywords:
- CBitmapButton [MFC], CBitmapButton
- CBitmapButton [MFC], AutoLoad
- CBitmapButton [MFC], LoadBitmaps
- CBitmapButton [MFC], SizeToContent
ms.assetid: 9ad6cb45-c3c4-4fb1-96d3-1fe3df7bbcfc
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d926e538cf9f9f1cb4935a1d53ba6c1fd7f4696e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cbitmapbutton-class"></a>Classe CBitmapButton
Cria os controles de botão de pressão rotulados com imagens de bitmap em vez de texto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CBitmapButton : public CButton  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
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
 `CBitmapButton`objetos contêm até quatro bitmaps, que contêm imagens para os diferentes estados em um botão pode assumir: ativo (ou normal), inativo (ou selecionada), com foco e desativado. Somente o primeiro bitmap é obrigatório. os outros são opcionais.  
  
 Imagens de bitmap botão incluir borda ao redor da imagem, bem como a própria imagem. A borda normalmente desempenha uma função na exibição de estado do botão. Por exemplo, o bitmap para o estado de foco normalmente é como um para o estado, mas com a inserção de um retângulo tracejado de borda ou uma linha sólida espessa na borda. O bitmap para o desabilitado estado geralmente é semelhante a um para o estado, mas tem menor contraste (como uma seleção de menu cinza ou esmaecidos).  
  
 Esses bitmaps podem ser de qualquer tamanho, mas são tratados como se fossem o mesmo tamanho que o bitmap para o estado.  
  
 Vários aplicativos exigem diferentes combinações de imagens de bitmap:  
  
|Acima|Abaixo|Focalizado|Disabled|Aplicativo|  
|--------|----------|-------------|--------------|-----------------|  
|×||||Bitmap|  
|×|×|||Botão sem **WS_TABSTOP** estilo|  
|×|×|×|×|Botão da caixa de diálogo com todos os estados|  
|×|×|×||Botão da caixa de diálogo com **WS_TABSTOP** estilo|  
  
 Ao criar um controle de botão de bitmap, defina o **BS_OWNERDRAW** estilo para especificar que o botão é desenhado pelo proprietário. Isso faz com que o Windows enviar o `WM_MEASUREITEM` e `WM_DRAWITEM` mensagens para o botão; o framework trata essas mensagens e gerencia a aparência do botão para você.  
  
### <a name="to-create-a-bitmap-button-control-in-a-windows-client-area"></a>Para criar um controle de botão de bitmap na área cliente da janela  
  
1.  Crie um a quatro imagens de bitmap do botão.  
  
2.  Construir o [CBitmapButton](#cbitmapbutton) objeto.  
  
3.  Chamar o [criar](../../mfc/reference/cbutton-class.md#create) função para criar o controle de botão do Windows e anexá-lo para o `CBitmapButton` objeto.  
  
4.  Chamar o [LoadBitmaps](#loadbitmaps) a função de membro para carregar os recursos de bitmap, depois no botão de bitmap é construído.  
  
### <a name="to-include-a-bitmap-button-control-in-a-dialog-box"></a>Para incluir um controle de botão de bitmap em uma caixa de diálogo  
  
1.  Crie um a quatro imagens de bitmap do botão.  
  
2.  Crie um modelo de caixa de diálogo com um botão de desenho proprietário posicionado onde você deseja que o botão de bitmap. Não importa o tamanho do botão no modelo.  
  
3.  Definir a legenda do botão para um valor como " **MYIMAGE**" e definir um símbolo do botão como **IDC_MYIMAGE**.  
  
4.  Script de recurso do aplicativo, dê a cada uma das imagens criadas para o botão ID construído acrescentando uma das letras "U", "D", "F" ou "X" (para cima, para baixo, com foco e desabilitado) para a cadeia de caracteres usada para a legenda do botão na etapa 3. Para a legenda do botão " **MYIMAGE**," por exemplo, as IDs seria " **MYIMAGEU**," " **MYIMAGED**," " **MYIMAGEF**," e " **MYIMAGEX**. " Você **deve** especifique a ID de seu bitmaps entre aspas duplas. Caso contrário, o editor de recurso atribuirá um número inteiro para o recurso e MFC falhará ao carregar a imagem.  
  
5.  Na classe de caixa de diálogo do aplicativo (derivado de `CDialog`), adicione um `CBitmapButton` objeto de membro.  
  
6.  No `CDialog` do objeto [OnInitDialog](../../mfc/reference/cdialog-class.md#oninitdialog) rotina, chamada de `CBitmapButton` do objeto [AutoLoad](#autoload) funcionar, usando como parâmetros de ID de controle do botão e o `CDialog` objeto **isso** ponteiro.  
  
 Se você desejar tratar mensagens de notificação do Windows, como **BN_CLICKED**, enviado por um controle de botão de bitmap para seu pai (geralmente uma classe derivada de **CDialog)**, adicionar ao `CDialog`-derivado um mapa de mensagem manipulador de mensagens e de entrada de função de membro para cada mensagem do objeto. As notificações enviadas por uma `CBitmapButton` objeto são iguais àquelas enviadas por uma [CButton](../../mfc/reference/cbutton-class.md) objeto.  
  
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
  
##  <a name="autoload"></a>CBitmapButton::AutoLoad  
 Associa um objeto de um botão em uma caixa de diálogo de `CBitmapButton` classe, carrega o bitmap(s) por nome e tamanhos de botão para ajustar o bitmap.  
  
```  
BOOL AutoLoad(
    UINT nID,  
    CWnd* pParent);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 ID de controle. do botão  
  
 `pParent`  
 Ponteiro para o objeto que possui o botão.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Use o `AutoLoad` função para inicializar um botão de desenho proprietário em uma caixa de diálogo como um botão de bitmap. Instruções para usar essa função são os comentários para o `CBitmapButton` classe.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCControlLadenDialog#75](../../mfc/codesnippet/cpp/cbitmapbutton-class_1.cpp)]  
  
##  <a name="cbitmapbutton"></a>CBitmapButton::CBitmapButton  
 Cria um objeto `CBitmapButton`.  
  
```  
CBitmapButton();
```  
  
### <a name="remarks"></a>Comentários  
 Depois de criar o C++ `CBitmapButton` de objeto, chame [CButton::Create](../../mfc/reference/cbutton-class.md#create) para criar o controle de botão do Windows e anexá-lo para o `CBitmapButton` objeto.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCControlLadenDialog#57](../../mfc/codesnippet/cpp/cbitmapbutton-class_2.cpp)]  
  
##  <a name="loadbitmaps"></a>CBitmapButton::LoadBitmaps  
 Use esta função quando quiser carregar imagens de bitmap identificadas por seus nomes de recursos ou os números de identificação, ou quando você não pode usar o `AutoLoad` funcionar porque, por exemplo, você está criando um botão de bitmap não é parte de uma caixa de diálogo.  
  
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
 Aponta para a cadeia de caracteres terminada em nulo que contém o nome do bitmap para um botão de bitmap do selecionado ou "estado desativado". Pode ser **nulo**.  
  
 *lpszBitmapResourceFocus*  
 Aponta para a cadeia de caracteres terminada em nulo que contém o nome do bitmap para um botão de bitmap voltada para o estado. Pode ser **nulo**.  
  
 *lpszBitmapResourceDisabled*  
 Aponta para a cadeia de caracteres terminada em nulo que contém o nome do bitmap para um botão de bitmap estado desabilitado. Pode ser **nulo**.  
  
 *nIDBitmapResource*  
 Especifica o número de identificação de recurso do recurso de bitmap para normal do botão um bitmap ou "backup" do estado. Necessário.  
  
 *nIDBitmapResourceSel*  
 Especifica o número de identificação de recurso do recurso de bitmap para um botão de bitmap do selecionado ou "estado desativado". Pode ser 0.  
  
 *nIDBitmapResourceFocus*  
 Especifica o número de identificação de recurso do recurso de bitmap para o estado de foco do botão um bitmap. Pode ser 0.  
  
 *nIDBitmapResourceDisabled*  
 Especifica o número de identificação de recurso do recurso de bitmap para estado desabilitado de um botão bitmap. Pode ser 0.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCControlLadenDialog#58](../../mfc/codesnippet/cpp/cbitmapbutton-class_3.cpp)]  
  
##  <a name="sizetocontent"></a>CBitmapButton::SizeToContent  
 Chame essa função para redimensionar um botão de bitmap para o tamanho do bitmap.  
  
```  
void SizeToContent();
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCControlLadenDialog#59](../../mfc/codesnippet/cpp/cbitmapbutton-class_4.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC CTRLTEST](../../visual-cpp-samples.md)   
 [Classe CButton](../../mfc/reference/cbutton-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)

