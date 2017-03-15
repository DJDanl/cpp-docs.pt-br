---
title: Classe CAnimateCtrl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CAnimateCtrl
dev_langs:
- C++
helpviewer_keywords:
- animation controls [C++], CAnimateCtrl class
- Windows common controls [C++], CAnimateCtrl class
- CAnimateCtrl class
ms.assetid: 5e8eb1bd-96b7-47b8-8de2-6bcbb3cc299b
caps.latest.revision: 25
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
ms.openlocfilehash: cef1d6274d5334804ee028fa296c77faf124a496
ms.lasthandoff: 02/25/2017

---
# <a name="canimatectrl-class"></a>Classe CAnimateCtrl
Fornece a funcionalidade do controle de animação comuns do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CAnimateCtrl : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimateCtrl::CAnimateCtrl](#canimatectrl)|Constrói um objeto `CAnimateCtrl`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimateCtrl::Close](#close)|Fecha o clipe AVI.|  
|[CAnimateCtrl::Create](#create)|Cria um controle de animação e a anexa a um `CAnimateCtrl` objeto.|  
|[CAnimateCtrl::CreateEx](#createex)|Cria um controle de animação com os estilos estendidos do Windows especificados e a anexa a um `CAnimateCtrl` objeto.|  
|[CAnimateCtrl::IsPlaying](#isplaying)|Indica se um clipe de áudio-vídeo intercalados (AVI) estiver em execução.|  
|[CAnimateCtrl::Open](#open)|Abre um clipe AVI de um arquivo ou recurso e exibe o primeiro quadro.|  
|[CAnimateCtrl::Play](#play)|Reproduz o clipe AVI sem som.|  
|[CAnimateCtrl::Seek](#seek)|Exibe um único quadro selecionado do clipe AVI.|  
|[CAnimateCtrl::Stop](#stop)|Interrompe a execução do clipe AVI.|  
  
## <a name="remarks"></a>Comentários  
 Esse controle (e, portanto, a `CAnimateCtrl` classe) está disponível apenas para programas em execução na versão do Windows 95, Windows 98 e Windows NT 3.51 e posterior.  
  
 Um controle de animação é uma janela retangular que exibe um clipe no formato AVI (áudio formato AVI) — o formato de áudio/vídeo do Windows padrão. Um clipe AVI é uma série de quadros de bitmap, como um filme.  
  
 Controles de animação podem reproduzir apenas os clipes AVI simples. Especificamente, os clipes para ser executado por um controle de animação devem atender aos seguintes requisitos:  
  
-   Deve haver exatamente um fluxo de vídeo e deve ter pelo menos um quadro.  
  
-   Pode haver no máximo dois fluxos no arquivo (normalmente o fluxo, se presente, é um fluxo de áudio, embora o controle de animação ignora informações áudios).  
  
-   O clipe deve ser descompactado ou compactado em RLE8.  
  
-   Nenhuma alteração de paleta é permitidas no fluxo de vídeo.  
  
 Você pode adicionar o clipe AVI para seu aplicativo como um recurso AVI, ou ele pode acompanhar seu aplicativo como um arquivo AVI separado.  
  
 Como o segmento continua executando enquanto o clipe AVI é exibido, um uso comum para um controle de animação é indicar a atividade do sistema durante uma operação demorada. Por exemplo, a caixa de diálogo Localizar do Explorador de arquivos exibe uma lupa móvel como o sistema procurará um arquivo.  
  
 Se você criar um `CAnimateCtrl` de objeto dentro de uma caixa de diálogo caixa ou de um recurso de caixa de diálogo usando o editor de caixa de diálogo, ele será ser destruído automaticamente quando o usuário fecha a caixa de diálogo.  
  
 Se você criar um `CAnimateCtrl` do objeto em uma janela, talvez você precise destruí-lo. Se você criar o `CAnimateCtrl` do objeto na pilha, ele será destruído automaticamente. Se você criar o `CAnimateCtrl` objeto no heap usando o **novo** função, você deve chamar **excluir** no objeto para destruí-lo. Se você derivar uma nova classe de `CAnimateCtrl` e alocar qualquer memória nessa classe, substituir o `CAnimateCtrl` destruidor descartar as alocações.  
  
 Para obter mais informações sobre como usar o `CAnimateCtrl`, consulte [controles](../../mfc/controls-mfc.md) e [CAnimateCtrl usando](../../mfc/using-canimatectrl.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CAnimateCtrl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcmn.h  
  
##  <a name="a-namecanimatectrla--canimatectrlcanimatectrl"></a><a name="canimatectrl"></a>CAnimateCtrl::CAnimateCtrl  
 Constrói um objeto `CAnimateCtrl`.  
  
```  
CAnimateCtrl();
```  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar o [criar](#create) função de membro antes de executar outras operações no objeto que você criar.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[56 NVC_MFCControlLadenDialog](../../mfc/codesnippet/cpp/canimatectrl-class_1.cpp)]  
  
##  <a name="a-nameclosea--canimatectrlclose"></a><a name="close"></a>CAnimateCtrl::Close  
 Fecha o clipe AVI que foi aberto anteriormente no controle de animação (se houver) e a remove da memória.  
  
```  
BOOL Close();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CAnimateCtrl::CAnimateCtrl](#canimatectrl).  
  
##  <a name="a-namecreatea--canimatectrlcreate"></a><a name="create"></a>CAnimateCtrl::Create  
 Cria um controle de animação e a anexa a um `CAnimateCtrl` objeto.  
  
```  
virtual BOOL Create(
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwStyle`  
 Especifica o estilo do controle de animação. Aplique qualquer combinação das janelas de estilos descritos na seção comentários abaixo e os estilos de controle de animação descritos em [estilos de controle de animação](http://msdn.microsoft.com/library/windows/desktop/bb761886) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `rect`  
 Especifica a posição e o tamanho do controle de animação. Ele pode ser um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou um [RECT](../../mfc/reference/rect-structure1.md) estrutura.  
  
 `pParentWnd`  
 Especifica a janela do pai do controle de animação, geralmente um `CDialog`. Ele não deve ser **nulo.**  
  
 `nID`  
 Especifica a identificação. do controle de animação  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Você construir um `CAnimateCtrl` em duas etapas. Primeiro, chame o construtor e, em seguida, chame **criar**, que cria o controle de animação e anexa-o para o `CAnimateCtrl` objeto.  
  
 Aplique o seguinte [estilos de janela](../../mfc/reference/window-styles.md) para um controle de animação.  
  
- **Estilo** sempre  
  
- **WS_VISIBLE** geral  
  
- **WS_DISABLED** raramente  
  
 Se você quiser usar estilos estendidos do windows com o controle de animação, chame [CreateEx](#createex) em vez de **criar**.  
  
 Além dos estilos de janela listados acima, você talvez queira aplicar um ou mais dos estilos de controle de animação a um controle de animação. Consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter mais informações sobre [estilos de controle de animação](http://msdn.microsoft.com/library/windows/desktop/bb761886).  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CAnimateCtrl::CAnimateCtrl](#canimatectrl).  
  
##  <a name="a-namecreateexa--canimatectrlcreateex"></a><a name="createex"></a>CAnimateCtrl::CreateEx  
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
 `dwExStyle`  
 Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista dos estilos estendidos do Windows, consulte o `dwExStyle` parâmetro [CreateWindowEx](http://msdn.microsoft.com/library/windows/desktop/ms632680) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `dwStyle`  
 Especifica o estilo do controle de animação. Aplique qualquer combinação de janela e estilos de controle de animação descritos na [estilos de controle de animação](http://msdn.microsoft.com/library/windows/desktop/bb761886) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `rect`  
 Uma referência a um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que descreve o tamanho e a posição da janela deve ser criada, nas coordenadas do cliente de `pParentWnd`.  
  
 `pParentWnd`  
 Um ponteiro para a janela que é o pai do controle.  
  
 `nID`  
 ID da janela filho. do controle  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Use `CreateEx` em vez de [criar](#create) para aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido Windows **WS_EX_**.  
  
##  <a name="a-nameisplayinga--canimatectrlisplaying"></a><a name="isplaying"></a>CAnimateCtrl::IsPlaying  
 Indica se um clipe de áudio-vídeo intercalados (AVI) estiver em execução.  
  
```  
BOOL IsPlaying() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se um clipe AVI estiver em execução; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [ACM_ISPLAYING](http://msdn.microsoft.com/library/windows/desktop/bb761895) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-nameopena--canimatectrlopen"></a><a name="open"></a>CAnimateCtrl::Open  
 Chame essa função para abrir um clipe AVI e exibir o primeiro quadro.  
  
```  
BOOL Open(LPCTSTR lpszFileName);  
BOOL Open(UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszFileName`  
 Um `CString` objeto ou um ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome do arquivo AVI ou o nome de um recurso AVI. Se esse parâmetro for **nulo**, o sistema fechará o clipe AVI aberto anteriormente para o controle de animação, se houver.  
  
 `nID`  
 O identificador do recurso AVI. Se esse parâmetro for **nulo**, o sistema fechará o clipe AVI aberto anteriormente para o controle de animação, se houver.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 O recurso AVI é carregado do módulo que criou o controle de animação.  
  
 **Abra** não oferece suporte a som em um clipe AVI; você pode abrir somente os clipes AVI silenciosos.  
  
 Se o controle de animação tem o `ACS_AUTOPLAY` estilo, o controle de animação será iniciado automaticamente execução do clipe imediatamente depois que ele é aberto. Ele continuará a reproduzir o clipe em segundo plano enquanto o thread continua em execução. Quando terminar o clipe em execução, ele será automaticamente repetido.  
  
 Se o controle de animação tem o `ACS_CENTER` estilo, o clipe AVI será centralizado no controle e o tamanho do controle não será alterado. Se o controle de animação não tiver o `ACS_CENTER` estilo, o controle é redimensionado quando o clipe AVI é aberto para o tamanho das imagens no clipe AVI. A posição do canto superior esquerdo do controle não será alterado, somente o tamanho do controle.  
  
 Se o controle de animação tem o `ACS_TRANSPARENT` estilo, o primeiro quadro será desenhado usando um plano de fundo transparente, em vez da cor de plano de fundo especificada no clipe de animação.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CAnimateCtrl::CAnimateCtrl](#canimatectrl).  
  
##  <a name="a-nameplaya--canimatectrlplay"></a><a name="play"></a>CAnimateCtrl::Play  
 Chame essa função para reproduzir um clipe AVI em um controle de animação.  
  
```  
BOOL Play(
    UINT nFrom,  
    UINT nTo,  
    UINT nRep);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nFrom`  
 Índice baseado em zero do quadro onde começa a execução. Valor deve ser menor que 65.536. Um valor de 0 significa que começa com o primeiro quadro do clipe AVI.  
  
 `nTo`  
 Índice baseado em zero do quadro em execução termina. Valor deve ser menor que 65.536. Um valor de – 1 significa que terminam com o último quadro no clipe AVI.  
  
 *nRep*  
 Número de vezes para repetir o clipe AVI. Um valor de-1 significa reproduzir o arquivo indefinidamente.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 O controle de animação reproduzirá o clipe em segundo plano enquanto o thread continua em execução. Se o controle de animação tem `ACS_TRANSPARENT` estilo, o clipe AVI será executado usando um plano de fundo transparente, em vez da cor de plano de fundo especificada no clipe de animação.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CAnimateCtrl::CAnimateCtrl](#canimatectrl).  
  
##  <a name="a-nameseeka--canimatectrlseek"></a><a name="seek"></a>CAnimateCtrl::Seek  
 Chame essa função para exibir um único quadro do clipe AVI estaticamente.  
  
```  
BOOL Seek(UINT nTo);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nTo`  
 Índice baseado em zero do quadro para exibir. Valor deve ser menor que 65.536. Um valor 0 significa exibir o primeiro quadro no clipe AVI. Um valor de-1 significa exibir o último quadro no clipe AVI.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Se o controle de animação tem `ACS_TRANSPARENT` estilo, o clipe AVI será desenhado usando um plano de fundo transparente, em vez da cor de plano de fundo especificada no clipe de animação.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CAnimateCtrl::CAnimateCtrl](#canimatectrl).  
  
##  <a name="a-namestopa--canimatectrlstop"></a><a name="stop"></a>CAnimateCtrl::Stop  
 Chame essa função para interromper a reprodução de um clipe AVI em um controle de animação.  
  
```  
BOOL Stop();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CAnimateCtrl::CAnimateCtrl](#canimatectrl).  
  
## <a name="see-also"></a>Consulte também  
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [CAnimateCtrl::Create](#create)   
 [ON_CONTROL](http://msdn.microsoft.com/library/2cb7ebdf-296b-4606-b191-3449835003db)


