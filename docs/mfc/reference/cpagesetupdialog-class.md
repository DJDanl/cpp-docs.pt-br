---
title: Classe CPageSetupDialog | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CPageSetupDialog
- AFXDLGS/CPageSetupDialog
- AFXDLGS/CPageSetupDialog::CPageSetupDialog
- AFXDLGS/CPageSetupDialog::CreatePrinterDC
- AFXDLGS/CPageSetupDialog::DoModal
- AFXDLGS/CPageSetupDialog::GetDeviceName
- AFXDLGS/CPageSetupDialog::GetDevMode
- AFXDLGS/CPageSetupDialog::GetDriverName
- AFXDLGS/CPageSetupDialog::GetMargins
- AFXDLGS/CPageSetupDialog::GetPaperSize
- AFXDLGS/CPageSetupDialog::GetPortName
- AFXDLGS/CPageSetupDialog::OnDrawPage
- AFXDLGS/CPageSetupDialog::PreDrawPage
- AFXDLGS/CPageSetupDialog::m_psd
dev_langs:
- C++
helpviewer_keywords:
- page setup
- Print Setup dialog box
- Page Setup dialog box
- OLE Page Setup dialog box
- CPageSetupDialog class
ms.assetid: 049c0ac8-f254-4854-9414-7a8271d1447a
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 81d36b3a005a291aca4c77dc9771a4fe92c304ee
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cpagesetupdialog-class"></a>Classe de CPageSetupDialog
Encapsula os serviços fornecidos pelo Windows comuns OLE página caixa de diálogo com suporte adicional para configuração e modificar as margens de impressão.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CPageSetupDialog : public CCommonDialog  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPageSetupDialog::CPageSetupDialog](#cpagesetupdialog)|Constrói um objeto `CPageSetupDialog`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPageSetupDialog::CreatePrinterDC](#createprinterdc)|Cria um contexto de dispositivo de impressão.|  
|[CPageSetupDialog::DoModal](#domodal)|Exibe a caixa de diálogo e permite que o usuário faça uma seleção.|  
|[CPageSetupDialog::GetDeviceName](#getdevicename)|Retorna o nome do dispositivo da impressora.|  
|[CPageSetupDialog::GetDevMode](#getdevmode)|Retorna o atual `DEVMODE` da impressora.|  
|[CPageSetupDialog::GetDriverName](#getdrivername)|Retorna o driver usado pela impressora.|  
|[CPageSetupDialog::GetMargins](#getmargins)|Retorna as atuais configurações de margem da impressora.|  
|[CPageSetupDialog::GetPaperSize](#getpapersize)|Retorna o tamanho do papel da impressora.|  
|[CPageSetupDialog::GetPortName](#getportname)|Retorna o nome da porta de saída.|  
|[CPageSetupDialog::OnDrawPage](#ondrawpage)|Chamado pela estrutura para processar uma imagem de tela de uma página impressa.|  
|[CPageSetupDialog::PreDrawPage](#predrawpage)|Chamado pela estrutura antes de processar uma imagem de tela de uma página impressa.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPageSetupDialog::m_psd](#m_psd)|Uma estrutura usada para personalizar um `CPageSetupDialog` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe foi projetada para tomar o lugar da caixa de diálogo Configurar impressão.  
  
 Para usar um `CPageSetupDialog` de objeto, primeiro crie o objeto usando o `CPageSetupDialog` construtor. Depois que a caixa de diálogo foi construída, você pode definir ou modificar qualquer valor de `m_psd` membro de dados para inicializar os valores dos controles da caixa de diálogo. O [m_psd](#m_psd) estrutura é do tipo **PAGESETUPDLG**.  
  
 Depois de inicializar os controles de caixa de diálogo, chame o `DoModal` a função de membro para exibir a caixa de diálogo e permitir que o usuário selecione as opções de impressão. `DoModal`Retorna se o usuário selecionou o Okey ( **IDOK**) ou Cancel ( **IDCANCEL**) botão.  
  
 Se `DoModal` retorna **IDOK**, você pode usar vários `CPageSetupDialog`de funções de membro ou acesso a `m_psd` membro de dados, para recuperar a entrada de informações pelo usuário.  
  
> [!NOTE]
>  Depois que a caixa de diálogo Configurar página OLE comum é descartada, todas as alterações feitas pelo usuário não serão salvas pelo framework. É responsabilidade do aplicativo para salvar quaisquer valores nessa caixa de diálogo para um local permanente, como membro da classe de aplicativo ou documento do aplicativo.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../../mfc/reference/ccommondialog-class.md)  
  
 `CPageSetupDialog`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdlgs. h  
  
##  <a name="cpagesetupdialog"></a>CPageSetupDialog::CPageSetupDialog  
 Chame essa função para construir uma `CPageSetupDialog` objeto.  
  
```  
CPageSetupDialog(
    DWORD dwFlags = PSD_MARGINS | PSD_INWININIINTLMEASURE,  
    CWnd* pParentWnd = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwFlags`  
 Um ou mais sinalizadores que você pode usar para personalizar as configurações da caixa de diálogo. Os valores podem ser combinados usando o operador OR bit a bit. Esses valores têm os seguintes significados:  
  
- **PSD_DEFAULTMINMARGINS** define as larguras mínimas permitidas para as margens da página ser igual ao mínimo da impressora. Este sinalizador é ignorado se o **PSD_MARGINS** e **PSD_MINMARGINS** sinalizadores também são especificados.  
  
- **PSD_INWININIINTLMEASURE** não implementado.  
  
- **PSD_MINMARGINS** faz com que o sistema use os valores especificados no **rtMinMargin** membro como as larguras mínimos permitidos para a esquerda, superior, direita e margens inferior. O sistema impede que o usuário inserir uma largura que é menor que o mínimo especificado. Se **PSD_MINMARGINS** não for especificado, o sistema define as larguras permitidas mínimas às permitidas pela impressora.  
  
- **PSD_MARGINS** ativa da área de controle de margem.  
  
- **PSD_INTHOUSANDTHSOFINCHES** faz com que as unidades de medida em 1/1000 de polegada da caixa de diálogo.  
  
- **PSD_INHUNDREDTHSOFMILLIMETERS** faz com que as unidades de medida em 1/100 de milímetro da caixa de diálogo.  
  
- **PSD_DISABLEMARGINS** desabilita os controles de caixa de diálogo de margem.  
  
- **PSD_DISABLEPRINTER** desativa o botão impressora.  
  
- **PSD_NOWARNING** impede que a mensagem de aviso seja exibido quando há uma impressora padrão.  
  
- **PSD_DISABLEORIENTATION** desabilita o controle de caixa de diálogo de orientação de página.  
  
- **PSD_RETURNDEFAULT** faz com que `CPageSetupDialog` para retornar [DEVMODE](http://msdn.microsoft.com/library/windows/desktop/dd183565) e [DEVNAMES](../../mfc/reference/devnames-structure.md) estruturas que são inicializadas para a impressora padrão do sistema sem exibir uma caixa de diálogo. Supõe-se que os dois **hDevNames** e **hDevMode** são **nulo**; caso contrário, a função retornará um erro. Se a impressora padrão do sistema é suportada por um driver de impressora antigo (anterior ao Windows versão 3.0), apenas **hDevNames** será retornado; **hDevMode** is **NULL**.  
  
- **PSD_DISABLEPAPER** desabilita o controle de seleção de documento.  
  
- **PSD_SHOWHELP** faz com que a caixa de diálogo Mostrar o botão Ajuda. O **hwndOwner** não deve ser membro **nulo** se este sinalizador for especificado.  
  
- **PSD_ENABLEPAGESETUPHOOK** permite que a função de gancho especificada em **lpfnSetupHook**.  
  
- **PSD_ENABLEPAGESETUPTEMPLATE** faz com que o sistema operacional criar a caixa de diálogo usando a caixa de diálogo modelo identificada por **hInstance** e **lpSetupTemplateName**.  
  
- **PSD_ENABLEPAGESETUPTEMPLATEHANDLE** indica que **hInstance** identifica um bloco de dados que contém um modelo de caixa de diálogo pré-carregado. O sistema ignora **lpSetupTemplateName** se este sinalizador for especificado.  
  
- **PSD_ENABLEPAGEPAINTHOOK** permite que a função de gancho especificada em **lpfnPagePaintHook**.  
  
- **PSD_DISABLEPAGEPAINTING** desabilita a área de desenho da caixa de diálogo.  
  
 `pParentWnd`  
 Ponteiro para o pai ou o proprietário da caixa de diálogo.  
  
### <a name="remarks"></a>Comentários  
 Use o [DoModal](../../mfc/reference/cdialog-class.md#domodal) função para exibir a caixa de diálogo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#94;](../../mfc/codesnippet/cpp/cpagesetupdialog-class_1.cpp)]  
  
##  <a name="createprinterdc"></a>CPageSetupDialog::CreatePrinterDC  
 Cria um contexto de dispositivo da impressora a [DEVMODE](http://msdn.microsoft.com/library/windows/desktop/dd183565) e [DEVNAMES](../../mfc/reference/devnames-structure.md) estruturas.  
  
```  
HDC CreatePrinterDC();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Identificador para o contexto de dispositivo da impressora recém-criado (DC).  
  
##  <a name="domodal"></a>CPageSetupDialog::DoModal  
 Chame essa função para exibir a caixa de diálogo de configuração de página OLE comuns do Windows e permite ao usuário selecionar várias opções de configuração de impressão, como as margens de impressão, o tamanho e a orientação do papel e impressora de destino.  
  
```  
virtual INT_PTR DoModal();
```  
  
### <a name="return-value"></a>Valor de retorno  
 **IDOK** ou **IDCANCEL**. Se **IDCANCEL** é retornado, chame o Windows [CommDlgExtendedError](http://msdn.microsoft.com/library/windows/desktop/ms646916) função para determinar se ocorreu um erro.  
  
 **IDOK** e **IDCANCEL** são constantes que indicam se o usuário selecionou o botão Okey ou Cancelar.  
  
### <a name="remarks"></a>Comentários  
 Além disso, o usuário pode acessar as opções de instalação de impressora, como o local de rede e propriedades específicas para a impressora selecionada.  
  
 Se você quiser inicializar as várias opções da caixa de diálogo Configurar página definindo membros do `m_psd` estrutura, você deve fazer isso antes de chamar `DoModal`, e depois que o objeto de caixa de diálogo é construído. Depois de chamar `DoModal`, chamar funções para recuperar as configurações ou entrada de informações pelo usuário na caixa de diálogo de outro membro.  
  
 Se você deseja propagar as configurações atuais inseridas pelo usuário, fazer uma chamada para [CWinApp::SelectPrinter](../../mfc/reference/cwinapp-class.md#selectprinter). Essa função usa as informações a partir de `CPageSetupDialog` do objeto e inicializa e seleciona uma nova impressora DC com os atributos apropriados.  
  
 [!code-cpp[NVC_MFCDocView&#95;](../../mfc/codesnippet/cpp/cpagesetupdialog-class_2.cpp)]  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CPageSetupDialog::CPageSetupDialog](#cpagesetupdialog).  
  
##  <a name="getdevicename"></a>CPageSetupDialog::GetDeviceName  
 Chame essa função após `DoModal` para recuperar o nome da impressora selecionada no momento.  
  
```  
CString GetDeviceName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O nome do dispositivo usado pelo **CPageSetupDialog** objeto.  
  
##  <a name="getdevmode"></a>CPageSetupDialog::GetDevMode  
 Chame essa função depois de chamar `DoModal` para recuperar informações sobre o contexto de dispositivo da impressora a `CPageSetupDialog` objeto.  
  
```  
LPDEVMODE GetDevMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O [DEVMODE](http://msdn.microsoft.com/library/windows/desktop/dd183565) estrutura de dados, que contém informações sobre o ambiente de um driver de impressão e a inicialização do dispositivo. Você deve desbloquear a memória usada por essa estrutura com o Windows [GlobalUnlock](http://msdn.microsoft.com/library/windows/desktop/aa366595) função, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getdrivername"></a>CPageSetupDialog::GetDriverName  
 Chame essa função depois de chamar [DoModal](../../mfc/reference/cprintdialog-class.md#domodal) para recuperar o nome do driver de dispositivo da impressora definida pelo sistema.  
  
```  
CString GetDriverName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` especificando o nome do driver definidos pelo sistema.  
  
### <a name="remarks"></a>Comentários  
 Usar um ponteiro para o `CString` objeto retornado por `GetDriverName` como o valor de `lpszDriverName` em uma chamada para [CDC::CreateDC](../../mfc/reference/cdc-class.md#createdc).  
  
##  <a name="getmargins"></a>CPageSetupDialog::GetMargins  
 Chame essa função após uma chamada para `DoModal` para recuperar as margens do driver de dispositivo da impressora.  
  
```  
void GetMargins(
    LPRECT lpRectMargins,  
    LPRECT lpRectMinMargins) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpRectMargins*  
 Ponteiro para uma [RECT](https://www.microsoftonedoc.com/#/organizations/e6f6a65cf14f462597b64ac058dbe1d0/projects/3fedad16-eaf1-41a6-8f96-0c1949c68f32/containers/a3daf831-1c5f-4bbe-964d-503870caf874/tocpaths/18113766-3975-4369-bc07-92e34cba712e/locales/en-us) estrutura ou [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto que descreve (em polegadas de 1/1000 ou 1/100 mm) as margens de impressão para a impressora selecionada no momento. Passar **nulo** para esse parâmetro, se você não estiver interessado nesse retângulo.  
  
 *lpRectMinMargins*  
 Ponteiro para uma `RECT` estrutura ou `CRect` objeto que descreve (em polegadas de 1/1000 ou 1/100 mm) as margens de impressão mínimas para a impressora selecionada no momento. Passar **nulo** para esse parâmetro, se você não estiver interessado nesse retângulo.  
  
##  <a name="getpapersize"></a>CPageSetupDialog::GetPaperSize  
 Chame essa função para recuperar o tamanho do papel selecionado para impressão.  
  
```  
CSize GetPaperSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto que contém o tamanho do papel (em polegadas de 1/1000 ou 1/100 mm) selecionado para impressão.  
  
##  <a name="getportname"></a>CPageSetupDialog::GetPortName  
 Chame essa função depois de chamar `DoModal` para recuperar o nome da porta da impressora selecionada no momento.  
  
```  
CString GetPortName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O nome da porta da impressora selecionada no momento.  
  
##  <a name="m_psd"></a>CPageSetupDialog::m_psd  
 Uma estrutura do tipo **PAGESETUPDLG**, cujos membros armazenam as características do objeto de caixa de diálogo.  
  
```  
PAGESETUPDLG m_psd;  
```  
  
### <a name="remarks"></a>Comentários  
 Depois de criar um `CPageSetupDialog` do objeto, você pode usar `m_psd` para definir vários aspectos da caixa de diálogo antes de chamar o `DoModal` função de membro.  
  
 Se você modificar o `m_psd` membro de dados diretamente, você substituirá qualquer comportamento padrão.  
  
 Para obter mais informações sobre o [PAGESETUPDLG](http://msdn.microsoft.com/library/windows/desktop/ms646842) estrutura, consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Veja o exemplo de [CPageSetupDialog::CPageSetupDialog](#cpagesetupdialog).  
  
##  <a name="ondrawpage"></a>CPageSetupDialog::OnDrawPage  
 Chamado pela estrutura para desenhar uma imagem de tela de uma página impressa.  
  
```  
virtual UINT OnDrawPage(
    CDC* pDC,  
    UINT nMessage,  
    LPRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Ponteiro para o contexto de dispositivo da impressora.  
  
 `nMessage`  
 Especifica uma mensagem indicando que a área da página que está sendo desenhada no momento. Pode ser uma das seguintes opções:  
  
- **WM_PSD_FULLPAGERECT** a área de página inteira.  
  
- **WM_PSD_MINMARGINRECT** margens mínimas atuais.  
  
- **WM_PSD_MARGINRECT** margens atuais.  
  
- **WM_PSD_GREEKTEXTRECT** conteúdo da página.  
  
- **WM_PSD_ENVSTAMPRECT** área reservada para uma representação do selo.  
  
- **WM_PSD_YAFULLPAGERECT** área para obter uma representação de endereço do remetente. Essa área abrange as bordas da área da página de exemplo.  
  
 `lpRect`  
 Ponteiro para uma [CRect](../../atl-mfc-shared/reference/crect-class.md) ou [RECT](https://www.microsoftonedoc.com/#/organizations/e6f6a65cf14f462597b64ac058dbe1d0/projects/3fedad16-eaf1-41a6-8f96-0c1949c68f32/containers/a3daf831-1c5f-4bbe-964d-503870caf874/tocpaths/18113766-3975-4369-bc07-92e34cba712e/locales/en-us) objeto contendo as coordenadas da área de desenho.  
  
### <a name="return-value"></a>Valor de retorno  
 Valor diferente de zero se lida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa imagem, em seguida, é exibida como parte da caixa de diálogo Configurar página OLE comuns. A implementação padrão desenha uma imagem de uma página de texto.  
  
 Substitua essa função para personalizar o desenho de uma área específica da imagem ou a imagem inteira. Você pode fazer isso usando um `switch` instrução com **caso** instruções para verificar o valor do `nMessage`. Por exemplo, para personalizar a renderização do conteúdo da imagem da página, você pode usar o código de exemplo a seguir:  
  
 [!code-cpp[NVC_MFCDocView&#96;](../../mfc/codesnippet/cpp/cpagesetupdialog-class_3.cpp)]  
  
 Observe que você não precisa lidar com todos os casos de `nMessage`. Você pode optar por manipular um componente da imagem, vários componentes de imagem ou toda a área.  
  
##  <a name="predrawpage"></a>CPageSetupDialog::PreDrawPage  
 Chamado pela estrutura antes de desenhar a imagem da tela de uma página impressa.  
  
```  
virtual UINT PreDrawPage(
    WORD wPaper,  
    WORD wFlags,  
    LPPAGESETUPDLG pPSD);
```  
  
### <a name="parameters"></a>Parâmetros  
 *wPaper*  
 Especifica um valor que indica o tamanho do papel. Esse valor pode ser um do **DMPAPER_** valores listados na descrição do [DEVMODE](http://msdn.microsoft.com/library/windows/desktop/dd183565) estrutura.  
  
 `wFlags`  
 Indica a orientação do papel ou do envelope, e se a impressora é uma matriz de pontos ou dispositivo HPPCL (Hewlett Packard Printer Control Language). Esse parâmetro pode ter um dos seguintes valores:  
  
-   0x001 papel em modo paisagem (matricial)  
  
-   0x003 papel em modo paisagem (HPPCL)  
  
-   0x005 de papel em modo retrato (matricial)  
  
-   0x007 de papel em modo retrato (HPPCL)  
  
-   0x00b envelope em modo paisagem (HPPCL)  
  
-   0x00d envelope em modo retrato (matricial)  
  
-   0x019 envelope em modo paisagem (matricial)  
  
-   0x01f envelope em modo retrato (matricial)  
  
 `pPSD`  
 Ponteiro para uma **PAGESETUPDLG** estrutura. Para obter mais informações sobre [PAGESETUPDLG](http://msdn.microsoft.com/library/windows/desktop/ms646842), consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="return-value"></a>Valor de retorno  
 Valor diferente de zero se lida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função para personalizar o desenho da imagem. Se você substituir essa função e retornar **TRUE**, você deve desenhar a imagem inteira. Se você substituir essa função e retornar **FALSE**, a imagem padrão inteiro é desenhada pelo framework.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC WORDPAD](../../visual-cpp-samples.md)   
 [Classe de CCommonDialog](../../mfc/reference/ccommondialog-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)




