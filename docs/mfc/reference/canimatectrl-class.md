---
title: Classe CAnimateCtrl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CAnimateCtrl
- AFXCMN/CAnimateCtrl
- AFXCMN/CAnimateCtrl::CAnimateCtrl
- AFXCMN/CAnimateCtrl::Close
- AFXCMN/CAnimateCtrl::Create
- AFXCMN/CAnimateCtrl::CreateEx
- AFXCMN/CAnimateCtrl::IsPlaying
- AFXCMN/CAnimateCtrl::Open
- AFXCMN/CAnimateCtrl::Play
- AFXCMN/CAnimateCtrl::Seek
- AFXCMN/CAnimateCtrl::Stop
dev_langs:
- C++
helpviewer_keywords:
- CAnimateCtrl [MFC], CAnimateCtrl
- CAnimateCtrl [MFC], Close
- CAnimateCtrl [MFC], Create
- CAnimateCtrl [MFC], CreateEx
- CAnimateCtrl [MFC], IsPlaying
- CAnimateCtrl [MFC], Open
- CAnimateCtrl [MFC], Play
- CAnimateCtrl [MFC], Seek
- CAnimateCtrl [MFC], Stop
ms.assetid: 5e8eb1bd-96b7-47b8-8de2-6bcbb3cc299b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3e786dc176558900223b2b482a7161abe5e0d84d
ms.sourcegitcommit: 6408139d5f5ff8928f056bde93d20eecb3520361
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/02/2018
ms.locfileid: "37336267"
---
# <a name="canimatectrl-class"></a>Classe CAnimateCtrl
Fornece a funcionalidade do controle de animação comum do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CAnimateCtrl : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimateCtrl::CAnimateCtrl](#canimatectrl)|Constrói um objeto `CAnimateCtrl`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimateCtrl::Close](#close)|Fecha o clipe AVI.|  
|[CAnimateCtrl::Create](#create)|Cria um controle de animação e anexa-o para um `CAnimateCtrl` objeto.|  
|[CAnimateCtrl::CreateEx](#createex)|Cria um controle de animação com os estilos estendidos do Windows especificados e anexa-o para um `CAnimateCtrl` objeto.|  
|[CAnimateCtrl::IsPlaying](#isplaying)|Indica se um clipe de vídeo de áudio intercalados (AVI) está em execução.|  
|[CAnimateCtrl::Open](#open)|Abre um clipe AVI de um arquivo ou recurso e exibe o primeiro quadro.|  
|[CAnimateCtrl::Play](#play)|Reproduz o clipe AVI sem som.|  
|[CAnimateCtrl::Seek](#seek)|Exibe um único quadro selecionado do clipe AVI.|  
|[CAnimateCtrl::Stop](#stop)|Interrompe a execução do clipe AVI.|  
  
## <a name="remarks"></a>Comentários  
 Esse controle (e, portanto, o `CAnimateCtrl` classe) está disponível somente para programas executados na versão do Windows 95, Windows 98 e Windows NT 3.51 e posterior.  
  
 Um controle de animação é uma janela retangular que exibe um clipe no formato AVI (áudio formato AVI) — o formato de áudio/vídeo do Windows padrão. Um clipe AVI é uma série de quadros de bitmap, como um filme.  
  
 Controles de animação podem reproduzir apenas os clipes AVI simples. Especificamente, os clipes para ser executado por um controle de animação devem atender aos seguintes requisitos:  
  
-   Deve haver exatamente um fluxo de vídeo e deve ter pelo menos um quadro.  
  
-   Pode haver no máximo dois fluxos no arquivo (normalmente o fluxo, se presente, é um fluxo de áudio, embora o controle de animação ignora informações de áudio).  
  
-   O clipe deve ser descompactado ou compactado com compactação RLE8.  
  
-   Nenhuma alteração de paleta é permitida no fluxo de vídeo.  
  
 Você pode adicionar o clipe AVI ao seu aplicativo como um recurso AVI, ou ele pode acompanhar o seu aplicativo como um arquivo separado do AVI.  
  
 Porque o thread continua executando enquanto o clipe AVI é exibido, um uso comum para um controle de animação é indicar a atividade do sistema durante uma operação demorada. Por exemplo, a caixa de diálogo Localizar do Explorador de arquivos exibe uma lupa móvel como o sistema procurará um arquivo.  
  
 Se você criar um `CAnimateCtrl` do objeto dentro de uma caixa de diálogo caixa ou de um recurso de caixa de diálogo usando o editor de caixa de diálogo, ele será ser destruído automaticamente quando o usuário fecha a caixa de diálogo.  
  
 Se você criar um `CAnimateCtrl` do objeto dentro de uma janela, talvez você precise destruí-lo. Se você criar o `CAnimateCtrl` do objeto na pilha, ele será destruído automaticamente. Se você criar o `CAnimateCtrl` objeto no heap usando a **novos** função, você deve chamar **excluir** no objeto a destruí-la. Se você derivar uma nova classe de `CAnimateCtrl` e alocar nenhuma memória nessa classe, substitua o `CAnimateCtrl` destruidor para dispose das alocações.  
  
 Para obter mais informações sobre como usar `CAnimateCtrl`, consulte [controles](../../mfc/controls-mfc.md) e [usando CAnimateCtrl](../../mfc/using-canimatectrl.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CAnimateCtrl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcmn. h  
  
##  <a name="canimatectrl"></a>  CAnimateCtrl::CAnimateCtrl  
 Constrói um objeto `CAnimateCtrl`.  
  
```  
CAnimateCtrl();
```  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar o [criar](#create) função de membro antes de executar outras operações no objeto que você cria.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCControlLadenDialog#56](../../mfc/codesnippet/cpp/canimatectrl-class_1.cpp)]  
  
##  <a name="close"></a>  CAnimateCtrl::Close  
 Fecha o clipe AVI que foi aberto anteriormente no controle de animação (se houver) e a remove da memória.  
  
```  
BOOL Close();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, zero.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CAnimateCtrl::CAnimateCtrl](#canimatectrl).  
  
##  <a name="create"></a>  CAnimateCtrl::Create  
 Cria um controle de animação e anexa-o para um `CAnimateCtrl` objeto.  
  
```  
virtual BOOL Create(
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwStyle*  
 Especifica o estilo do controle de animação. Aplicar qualquer combinação das janelas de estilos descritos na seção comentários abaixo e os estilos de controle de animação são descritos em [estilos de controle de animação](http://msdn.microsoft.com/library/windows/desktop/bb761886) no SDK do Windows.  
  
 *Rect*  
 Especifica a posição e o tamanho do controle de animação. Ela pode ser um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou uma [RECT](../../mfc/reference/rect-structure1.md) estrutura.  
  
 *pParentWnd*  
 Especifica a janela do pai do controle de animação, geralmente um `CDialog`. Ele não deve ser NULL.  
  
 *nID*  
 Especifica a ID. do controle de animação  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Você constrói um `CAnimateCtrl` em duas etapas. Primeiro, chame o construtor e, em seguida, chame `Create`, que cria o controle de animação e anexa-o para o `CAnimateCtrl` objeto.  
  
 Aplicar o seguinte [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) para um controle de animação.  
  
- Sempre WS_CHILD  
  
- Normalmente, WS_VISIBLE  
  
- WS_DISABLED raramente  
  
 Se você quiser usar estilos estendidos do windows com o controle de animação, chame [CreateEx](#createex) em vez de `Create`.  
  
 Além dos estilos de janela listados acima, você talvez queira aplicar um ou mais dos estilos de controle de animação a um controle de animação. Consulte o SDK do Windows para obter mais informações sobre [estilos de controle de animação](http://msdn.microsoft.com/library/windows/desktop/bb761886).  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CAnimateCtrl::CAnimateCtrl](#canimatectrl).  
  
##  <a name="createex"></a>  CAnimateCtrl::CreateEx  
 Cria um controle (uma janela filho) e o associa a `CAnimateCtrl` objeto.  
  
```  
virtual BOOL CreateEx(
    DWORD dwExStyle,  
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwExStyle*  
 Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista dos estilos estendidos do Windows, consulte o *dwExStyle* parâmetro para [CreateWindowEx](http://msdn.microsoft.com/library/windows/desktop/ms632680) no SDK do Windows.  
  
 *dwStyle*  
 Especifica o estilo do controle de animação. Aplicar qualquer combinação da janela e estilos de controle de animação descritos em [estilos de controle de animação](http://msdn.microsoft.com/library/windows/desktop/bb761886) no SDK do Windows.  
  
 *Rect*  
 Uma referência a um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que descreve o tamanho e posição da janela a ser criado, em coordenadas do cliente do *pParentWnd*.  
  
 *pParentWnd*  
 Um ponteiro para a janela que é o pai do controle.  
  
 *nID*  
 ID da janela filho. do controle  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Use `CreateEx` em vez de [Create](#create) para aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido do Windows **WS_EX_**.  
  
##  <a name="isplaying"></a>  CAnimateCtrl::IsPlaying  
 Indica se um clipe de vídeo de áudio intercalados (AVI) está em execução.  
  
```  
BOOL IsPlaying() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se um clipe AVI estiver em execução; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [ACM_ISPLAYING](http://msdn.microsoft.com/library/windows/desktop/bb761895) mensagem, que é descrita no SDK do Windows.  
  
##  <a name="open"></a>  CAnimateCtrl::Open  
 Chame essa função para abrir um clipe AVI e exibir seu primeiro quadro.  
  
```  
BOOL Open(LPCTSTR lpszFileName);  
BOOL Open(UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszFileName*  
 Um `CString` objeto ou um ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome do arquivo AVI ou o nome de um recurso AVI. Se esse parâmetro for NULL, o sistema fecha o clipe AVI que foi aberto anteriormente para o controle de animação, se houver.  
  
 *nID*  
 O identificador de recurso AVI. Se esse parâmetro for NULL, o sistema fecha o clipe AVI que foi aberto anteriormente para o controle de animação, se houver.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 O recurso AVI é carregado do módulo que criou o controle de animação.  
  
 `Open` não oferece suporte a som em um clipe AVI; Você pode abrir somente os clipes AVI silenciosos.  
  
 Se o controle de animação tem o `ACS_AUTOPLAY` estilo, o controle de animação começa a reproduzir automaticamente o clipe imediatamente depois que ela é aberta. Ele continuará a reproduzir o clipe em segundo plano enquanto o thread continua em execução. Quando o clipe é feito em execução, ele será automaticamente repetido.  
  
 Se o controle de animação tem o `ACS_CENTER` estilo, o clipe AVI será centralizado no controle e o tamanho do controle não será alterado. Se o controle de animação não tiver o `ACS_CENTER` estilo, o controle é redimensionado quando o clipe AVI é aberto para o tamanho das imagens no clipe AVI. A posição do canto superior esquerdo do controle não será alterado, somente o tamanho do controle.  
  
 Se o controle de animação tem o `ACS_TRANSPARENT` estilo, o primeiro quadro será desenhado usando um plano de fundo transparente, em vez da cor do plano de fundo especificada no clipe de animação.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CAnimateCtrl::CAnimateCtrl](#canimatectrl).  
  
##  <a name="play"></a>  CAnimateCtrl::Play  
 Chame essa função para reproduzir um clipe AVI em um controle de animação.  
  
```  
BOOL Play(
    UINT nFrom,  
    UINT nTo,  
    UINT nRep);
```  
  
### <a name="parameters"></a>Parâmetros  
 *NDE*  
 Índice baseado em zero do quadro em que a execução começa. Valor deve ser menor que 65.536. Um valor de 0 significa que começa com o primeiro quadro o clipe AVI.  
  
 *nPara*  
 O índice baseado em zero do quadro no qual a reprodução de extremidades. Valor deve ser menor que 65.536. Um valor de - 1 significa que terminam com o último quadro em que o clipe AVI.  
  
 *nRep*  
 Número de vezes para repetir o clipe AVI. Um valor de - 1 significa que o arquivo de reprodução por tempo indeterminado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 O controle de animação reproduzirá o clipe em segundo plano enquanto o thread continua em execução. Se o controle de animação tem `ACS_TRANSPARENT` estilo, o clipe AVI será executado usando um plano de fundo transparente em vez da cor de plano de fundo especificada no clipe de animação.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CAnimateCtrl::CAnimateCtrl](#canimatectrl).  
  
##  <a name="seek"></a>  CAnimateCtrl::Seek  
 Chame essa função para exibir um único quadro do clipe AVI de estaticamente.  
  
```  
BOOL Seek(UINT nTo);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nPara*  
 Índice baseado em zero do quadro para exibir. Valor deve ser menor que 65.536. Um valor de 0 significa exibir o primeiro quadro em que o clipe AVI. Um valor -1 significa exibir o último quadro em que o clipe AVI.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Se o controle de animação tem `ACS_TRANSPARENT` estilo, o clipe AVI será desenhado usando um plano de fundo transparente, em vez da cor do plano de fundo especificada no clipe de animação.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CAnimateCtrl::CAnimateCtrl](#canimatectrl).  
  
##  <a name="stop"></a>  CAnimateCtrl::Stop  
 Chame essa função para interromper a reprodução de um clipe AVI em um controle de animação.  
  
```  
BOOL Stop();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, zero.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CAnimateCtrl::CAnimateCtrl](#canimatectrl).  
  
## <a name="see-also"></a>Consulte também  
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [CAnimateCtrl::Create](#create)   
 [ON_CONTROL](message-map-macros-mfc.md#on_control)

