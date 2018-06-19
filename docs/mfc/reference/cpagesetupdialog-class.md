---
title: Classe CPageSetupDialog | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
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
- CPageSetupDialog [MFC], CPageSetupDialog
- CPageSetupDialog [MFC], CreatePrinterDC
- CPageSetupDialog [MFC], DoModal
- CPageSetupDialog [MFC], GetDeviceName
- CPageSetupDialog [MFC], GetDevMode
- CPageSetupDialog [MFC], GetDriverName
- CPageSetupDialog [MFC], GetMargins
- CPageSetupDialog [MFC], GetPaperSize
- CPageSetupDialog [MFC], GetPortName
- CPageSetupDialog [MFC], OnDrawPage
- CPageSetupDialog [MFC], PreDrawPage
- CPageSetupDialog [MFC], m_psd
ms.assetid: 049c0ac8-f254-4854-9414-7a8271d1447a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1cffe2d337d611dff0387805c99965c3c2e9ef87
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33374643"
---
# <a name="cpagesetupdialog-class"></a>Classe CPageSetupDialog
Encapsula os serviços fornecidos pela caixa de diálogo de configuração de página OLE comuns do Windows com suporte adicional para configuração e modificar as margens de impressão.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CPageSetupDialog : public CCommonDialog  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPageSetupDialog::CPageSetupDialog](#cpagesetupdialog)|Constrói um objeto `CPageSetupDialog`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPageSetupDialog::CreatePrinterDC](#createprinterdc)|Cria um contexto de dispositivo para impressão.|  
|[CPageSetupDialog::DoModal](#domodal)|Exibe a caixa de diálogo e permite que o usuário fazer uma seleção.|  
|[CPageSetupDialog::GetDeviceName](#getdevicename)|Retorna o nome do dispositivo da impressora.|  
|[CPageSetupDialog::GetDevMode](#getdevmode)|Retorna o atual `DEVMODE` da impressora.|  
|[CPageSetupDialog::GetDriverName](#getdrivername)|Retorna o driver de impressora.|  
|[CPageSetupDialog::GetMargins](#getmargins)|Retorna as atuais configurações de margem da impressora.|  
|[CPageSetupDialog::GetPaperSize](#getpapersize)|Retorna o tamanho do papel da impressora.|  
|[CPageSetupDialog::GetPortName](#getportname)|Retorna o nome de porta de saída.|  
|[CPageSetupDialog::OnDrawPage](#ondrawpage)|Chamado pelo framework para renderizar uma imagem de tela de uma página impressa.|  
|[CPageSetupDialog::PreDrawPage](#predrawpage)|Chamado pelo framework antes de processar uma imagem de tela de uma página impressa.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPageSetupDialog::m_psd](#m_psd)|Uma estrutura usada para personalizar um `CPageSetupDialog` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe foi projetada para tomar o lugar da caixa de diálogo Configurar impressão.  
  
 Para usar um `CPageSetupDialog` de objeto, primeiro crie o objeto usando o `CPageSetupDialog` construtor. Depois que a caixa de diálogo foi construída, você pode definir ou modificar valores no `m_psd` membro de dados para inicializar os valores de controles da caixa de diálogo. O [m_psd](#m_psd) estrutura é do tipo **PAGESETUPDLG**.  
  
 Depois de inicializar os controles de caixa de diálogo, chamar o `DoModal` a função de membro para exibir a caixa de diálogo e permitir que o usuário selecionar opções de impressão. `DoModal` Retorna se o usuário selecionou o Okey ( **IDOK**) ou Cancelar ( **IDCANCEL**) botão.  
  
 Se `DoModal` retorna **IDOK**, você pode usar vários `CPageSetupDialog`de funções de membro, ou acesso a `m_psd` membro de dados, para recuperar a entrada de informações pelo usuário.  
  
> [!NOTE]
>  Depois que a caixa de diálogo Configurar página OLE comum é descartada, todas as alterações feitas pelo usuário não serão salvas pelo framework. É responsabilidade do aplicativo para salvar valores nessa caixa de diálogo para um local permanente, como membro da classe de aplicativo ou documento do aplicativo.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../../mfc/reference/ccommondialog-class.md)  
  
 `CPageSetupDialog`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdlgs.h  
  
##  <a name="cpagesetupdialog"></a>  CPageSetupDialog::CPageSetupDialog  
 Chamar essa função para construir um `CPageSetupDialog` objeto.  
  
```  
CPageSetupDialog(
    DWORD dwFlags = PSD_MARGINS | PSD_INWININIINTLMEASURE,  
    CWnd* pParentWnd = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwFlags`  
 Um ou mais sinalizadores que você pode usar para personalizar as configurações da caixa de diálogo. Os valores podem ser combinados usando o operador OR bit a bit. Esses valores têm os seguintes significados:  
  
- **PSD_DEFAULTMINMARGINS** define as larguras mínimas permitidas para as margens de página ser o mesmo que mínimos da impressora. Este sinalizador será ignorado se o **PSD_MARGINS** e **PSD_MINMARGINS** sinalizadores também são especificados.  
  
- **PSD_INWININIINTLMEASURE** não implementado.  
  
- **PSD_MINMARGINS** faz com que o sistema a usar os valores especificados no **rtMinMargin** membro como as larguras mínimas permitidas para a esquerda, superior, direita e margens inferior. O sistema impede que o usuário inserir uma largura que é menor que o mínimo especificado. Se **PSD_MINMARGINS** não for especificado, o sistema define o mínimo permitidas larguras às permitidas da impressora.  
  
- **PSD_MARGINS** ativa da área de controle de margem.  
  
- **PSD_INTHOUSANDTHSOFINCHES** faz com que as unidades de medida em 1/1000 de polegada da caixa de diálogo.  
  
- **PSD_INHUNDREDTHSOFMILLIMETERS** faz com que as unidades de medida em 1/100 de milímetro da caixa de diálogo.  
  
- **PSD_DISABLEMARGINS** desabilita os controles de caixa de diálogo de margem.  
  
- **PSD_DISABLEPRINTER** desativa o botão impressora.  
  
- **PSD_NOWARNING** impede que a mensagem de aviso seja exibido quando não houver nenhuma impressora padrão.  
  
- **PSD_DISABLEORIENTATION** desabilita o controle de caixa de diálogo de orientação de página.  
  
- **PSD_RETURNDEFAULT** faz com que `CPageSetupDialog` para retornar [DEVMODE](http://msdn.microsoft.com/library/windows/desktop/dd183565) e [DEVNAMES](../../mfc/reference/devnames-structure.md) estruturas que são inicializadas para a impressora padrão do sistema sem exibir uma caixa de diálogo. Supõe-se que os dois **hDevNames** e **hDevMode** são **nulo**; caso contrário, a função retornará um erro. Se a impressora padrão do sistema é suportada por um driver de impressora antigo (anterior ao Windows versão 3.0), somente **hDevNames** é retornado; **hDevMode** é **nulo**.  
  
- **PSD_DISABLEPAPER** desabilita o controle de seleção de papel.  
  
- **PSD_SHOWHELP** faz com que a caixa de diálogo Mostrar o botão Ajuda. O **hwndOwner** não deve ser membro **nulo** se esse sinalizador for especificado.  
  
- **PSD_ENABLEPAGESETUPHOOK** permite que a função de gancho especificada em **lpfnSetupHook**.  
  
- **PSD_ENABLEPAGESETUPTEMPLATE** faz com que o sistema operacional criar a caixa de diálogo usando a caixa de diálogo modelo identificada por **hInstance** e **lpSetupTemplateName**.  
  
- **PSD_ENABLEPAGESETUPTEMPLATEHANDLE** indica que **hInstance** identifica um bloco de dados que contém um modelo de caixa de diálogo pré-carregados. O sistema ignora **lpSetupTemplateName** se esse sinalizador for especificado.  
  
- **PSD_ENABLEPAGEPAINTHOOK** permite que a função de gancho especificada em **lpfnPagePaintHook**.  
  
- **PSD_DISABLEPAGEPAINTING** desabilita a área de desenho da caixa de diálogo.  
  
 `pParentWnd`  
 Ponteiro para o pai ou o proprietário da caixa de diálogo.  
  
### <a name="remarks"></a>Comentários  
 Use o [DoModal](../../mfc/reference/cdialog-class.md#domodal) função para exibir a caixa de diálogo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#94](../../mfc/codesnippet/cpp/cpagesetupdialog-class_1.cpp)]  
  
##  <a name="createprinterdc"></a>  CPageSetupDialog::CreatePrinterDC  
 Cria um contexto de dispositivo de impressora do [DEVMODE](http://msdn.microsoft.com/library/windows/desktop/dd183565) e [DEVNAMES](../../mfc/reference/devnames-structure.md) estruturas.  
  
```  
HDC CreatePrinterDC();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Identificador para o contexto de dispositivo de impressora recém-criado (DC).  
  
##  <a name="domodal"></a>  CPageSetupDialog::DoModal  
 Chame essa função para exibir a caixa de diálogo de configuração de página OLE comuns do Windows e permitir que o usuário selecionar várias opções de configuração de impressão, como as margens de impressão, o tamanho e a orientação do papel e impressora de destino.  
  
```  
virtual INT_PTR DoModal();
```  
  
### <a name="return-value"></a>Valor de retorno  
 **IDOK** ou **IDCANCEL**. Se **IDCANCEL** é retornado, chame o Windows [CommDlgExtendedError](http://msdn.microsoft.com/library/windows/desktop/ms646916) função para determinar se ocorreu um erro.  
  
 **IDOK** e **IDCANCEL** são constantes que indicam se o usuário selecionou o botão Okey ou em Cancelar.  
  
### <a name="remarks"></a>Comentários  
 Além disso, o usuário pode acessar as opções de instalação de impressora, como o local de rede e propriedades específicas para a impressora selecionada.  
  
 Se você quiser inicializar as várias opções de caixa de diálogo Configurar página definindo membros do `m_psd` estrutura, você deve fazer isso antes de chamar `DoModal`, e depois que o objeto de caixa de diálogo é construído. Depois de chamar `DoModal`, chamar funções para recuperar as configurações ou a entrada de informações pelo usuário na caixa de diálogo de outro membro.  
  
 Se você quiser a propagação das configurações atuais inseridas pelo usuário, fazer uma chamada para [CWinApp::SelectPrinter](../../mfc/reference/cwinapp-class.md#selectprinter). Essa função usa as informações a partir de `CPageSetupDialog` do objeto e inicializa e seleciona uma nova impressora de controlador de domínio com os atributos apropriados.  
  
 [!code-cpp[NVC_MFCDocView#95](../../mfc/codesnippet/cpp/cpagesetupdialog-class_2.cpp)]  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CPageSetupDialog::CPageSetupDialog](#cpagesetupdialog).  
  
##  <a name="getdevicename"></a>  CPageSetupDialog::GetDeviceName  
 Chamar essa função após `DoModal` para recuperar o nome da impressora selecionada no momento.  
  
```  
CString GetDeviceName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O nome do dispositivo usado pelo **CPageSetupDialog** objeto.  
  
##  <a name="getdevmode"></a>  CPageSetupDialog::GetDevMode  
 Chamar essa função depois de chamar `DoModal` para recuperar informações sobre o contexto de dispositivo de impressora a `CPageSetupDialog` objeto.  
  
```  
LPDEVMODE GetDevMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O [DEVMODE](http://msdn.microsoft.com/library/windows/desktop/dd183565) estrutura de dados, que contém informações sobre a inicialização do dispositivo e o ambiente de um driver de impressão. Você deve desbloquear a memória usada por esta estrutura com o Windows [GlobalUnlock](http://msdn.microsoft.com/library/windows/desktop/aa366595) função, que é descrita no SDK do Windows.  
  
##  <a name="getdrivername"></a>  CPageSetupDialog::GetDriverName  
 Chamar essa função depois de chamar [DoModal](../../mfc/reference/cprintdialog-class.md#domodal) para recuperar o nome do driver de dispositivo de impressora definidas pelo sistema.  
  
```  
CString GetDriverName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` especificando o nome do driver definidos pelo sistema.  
  
### <a name="remarks"></a>Comentários  
 Usar um ponteiro para o `CString` objeto retornado por `GetDriverName` como o valor de `lpszDriverName` em uma chamada para [CDC::CreateDC](../../mfc/reference/cdc-class.md#createdc).  
  
##  <a name="getmargins"></a>  CPageSetupDialog::GetMargins  
 Chamar essa função após uma chamada para `DoModal` para recuperar as margens do driver de dispositivo de impressora.  
  
```  
void GetMargins(
    LPRECT lpRectMargins,  
    LPRECT lpRectMinMargins) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpRectMargins*  
 Ponteiro para um [RECT](https://www.microsoftonedoc.com/#/organizations/e6f6a65cf14f462597b64ac058dbe1d0/projects/3fedad16-eaf1-41a6-8f96-0c1949c68f32/containers/a3daf831-1c5f-4bbe-964d-503870caf874/tocpaths/18113766-3975-4369-bc07-92e34cba712e/locales/en-us) estrutura ou [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto que descreve (em polegadas de 1/1000 ou 1/100 mm) as margens de impressão da impressora selecionada no momento. Passar **nulo** para esse parâmetro, se você não estiver interessado nesse retângulo.  
  
 *lpRectMinMargins*  
 Ponteiro para um `RECT` estrutura ou `CRect` objeto que descreve (em polegadas de 1/1000 ou 1/100 mm) as margens de impressão mínimas para a impressora selecionada no momento. Passar **nulo** para esse parâmetro, se você não estiver interessado nesse retângulo.  
  
##  <a name="getpapersize"></a>  CPageSetupDialog::GetPaperSize  
 Chame essa função para recuperar o tamanho do papel selecionado para impressão.  
  
```  
CSize GetPaperSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto que contém o tamanho do papel (em polegadas de 1/1000 ou 1/100 mm) selecionado para impressão.  
  
##  <a name="getportname"></a>  CPageSetupDialog::GetPortName  
 Chamar essa função depois de chamar `DoModal` para recuperar o nome da porta da impressora selecionada no momento.  
  
```  
CString GetPortName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O nome da porta da impressora selecionada no momento.  
  
##  <a name="m_psd"></a>  CPageSetupDialog::m_psd  
 Uma estrutura de tipo **PAGESETUPDLG**, cujos membros armazenam as características do objeto de caixa de diálogo.  
  
```  
PAGESETUPDLG m_psd;  
```  
  
### <a name="remarks"></a>Comentários  
 Depois de construir um `CPageSetupDialog` do objeto, você pode usar `m_psd` para definir vários aspectos da caixa de diálogo antes de chamar o `DoModal` função de membro.  
  
 Se você modificar o `m_psd` membro de dados diretamente, você substituirá qualquer comportamento padrão.  
  
 Para obter mais informações sobre o [PAGESETUPDLG](http://msdn.microsoft.com/library/windows/desktop/ms646842) estrutura, consulte o SDK do Windows.  
  
 Consulte o exemplo para [CPageSetupDialog::CPageSetupDialog](#cpagesetupdialog).  
  
##  <a name="ondrawpage"></a>  CPageSetupDialog::OnDrawPage  
 Chamado pelo framework para desenhar uma imagem de tela de uma página impressa.  
  
```  
virtual UINT OnDrawPage(
    CDC* pDC,  
    UINT nMessage,  
    LPRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Ponteiro para o contexto de dispositivo de impressora.  
  
 `nMessage`  
 Especifica uma mensagem indicando que a área da página que está sendo desenhada no momento. Pode ser um dos seguintes:  
  
- **WM_PSD_FULLPAGERECT** a área de página inteira.  
  
- **WM_PSD_MINMARGINRECT** margens mínimo atuais.  
  
- **WM_PSD_MARGINRECT** margens atuais.  
  
- **WM_PSD_GREEKTEXTRECT** conteúdo da página.  
  
- **WM_PSD_ENVSTAMPRECT** área reservada para uma representação de selo.  
  
- **WM_PSD_YAFULLPAGERECT** área para obter uma representação de endereço de retorno. Essa área se estende até as bordas da área da página de exemplo.  
  
 `lpRect`  
 Ponteiro para um [CRect](../../atl-mfc-shared/reference/crect-class.md) ou [RECT](https://www.microsoftonedoc.com/#/organizations/e6f6a65cf14f462597b64ac058dbe1d0/projects/3fedad16-eaf1-41a6-8f96-0c1949c68f32/containers/a3daf831-1c5f-4bbe-964d-503870caf874/tocpaths/18113766-3975-4369-bc07-92e34cba712e/locales/en-us) objeto que contém as coordenadas da área de desenho.  
  
### <a name="return-value"></a>Valor de retorno  
 Valor diferente de zero se tratadas; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esta imagem é exibida como parte da caixa de diálogo Configurar página OLE comuns. A implementação padrão desenha uma imagem de uma página de texto.  
  
 Substitua essa função para personalizar o desenho de uma área específica da imagem ou a imagem inteira. Você pode fazer isso usando um `switch` instrução com **caso** instruções para verificar o valor do `nMessage`. Por exemplo, para personalizar a renderização do conteúdo da imagem da página, você pode usar o código de exemplo a seguir:  
  
 [!code-cpp[NVC_MFCDocView#96](../../mfc/codesnippet/cpp/cpagesetupdialog-class_3.cpp)]  
  
 Observe que você não precisa lidar com todos os casos de `nMessage`. Você pode escolher lidar com um componente de imagem, vários componentes de imagem ou toda a área.  
  
##  <a name="predrawpage"></a>  CPageSetupDialog::PreDrawPage  
 Chamado pelo framework antes do desenho de imagem de tela de uma página impressa.  
  
```  
virtual UINT PreDrawPage(
    WORD wPaper,  
    WORD wFlags,  
    LPPAGESETUPDLG pPSD);
```  
  
### <a name="parameters"></a>Parâmetros  
 *wPaper*  
 Especifica um valor que indica o tamanho do papel. Esse valor pode ser uma da **DMPAPER_** valores listados na descrição do [DEVMODE](http://msdn.microsoft.com/library/windows/desktop/dd183565) estrutura.  
  
 `wFlags`  
 Indica a orientação do papel ou do envelope, e se a impressora é uma matriz de ponto ou dispositivo HPPCL (linguagem de controle de impressora da Hewlett Packard). Esse parâmetro pode ter um dos seguintes valores:  
  
-   0x001 papel em modo de paisagem (matriz de ponto)  
  
-   0x003 papel em modo de paisagem (HPPCL)  
  
-   0x005 de papel em modo de retrato (matriz de ponto)  
  
-   0x007 de papel em modo de retrato (HPPCL)  
  
-   0x00b envelope em modo de paisagem (HPPCL)  
  
-   0x00d envelope em modo de retrato (matriz de ponto)  
  
-   0x019 envelope em modo de paisagem (matriz de ponto)  
  
-   0x01f envelope em modo de retrato (matriz de ponto)  
  
 `pPSD`  
 Ponteiro para um **PAGESETUPDLG** estrutura. Para obter mais informações sobre [PAGESETUPDLG](http://msdn.microsoft.com/library/windows/desktop/ms646842), consulte o SDK do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Valor diferente de zero se tratadas; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função para personalizar o desenho da imagem. Se você substituir esta função e retornar **TRUE**, você deve desenhar a imagem inteira. Se você substituir esta função e retornar **FALSE**, a imagem padrão inteiro é desenhada pelo framework.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC WORDPAD](../../visual-cpp-samples.md)   
 [Classe CCommonDialog](../../mfc/reference/ccommondialog-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)



