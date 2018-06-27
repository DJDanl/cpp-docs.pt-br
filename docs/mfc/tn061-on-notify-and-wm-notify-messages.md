---
title: 'TN061: Mensagens ON_NOTIFY e WM_NOTIFY | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- ON_NOTIFY
- WM_NOTIFY
dev_langs:
- C++
helpviewer_keywords:
- ON_NOTIFY_EX message [MFC]
- TN061
- ON_NOTIFY message [MFC]
- ON_NOTIFY_EX_RANGE message [MFC]
- ON_NOTIFY_RANGE message [MFC]
- notification messages
- WM_NOTIFY message
ms.assetid: 04a96dde-7049-41df-9954-ad7bb5587caf
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4afa05fa8bf21b6e324e9ac14a1b092933a99d55
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36954416"
---
# <a name="tn061-onnotify-and-wmnotify-messages"></a>TN061: mensagens ON_NOTIFY e WM_NOTIFY
> [!NOTE]
>  A Observação técnica a seguir não foi atualizada desde que ele foi incluído primeiro na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação on-line.  
  
 Essa observação técnica fornece informações básicas sobre a nova mensagem WM_NOTIFY e descreve a forma recomendada (e mais comum) de manipulação de mensagens WM_NOTIFY em seu aplicativo do MFC.  
  
 **Mensagens de notificação no Windows 3. x**  
  
 No Windows 3. x, controles notificar seus pais de eventos, como cliques do mouse, alterações no conteúdo e seleção de pintura do plano de fundo de controle enviando uma mensagem para o pai. Simples notificações são enviadas como mensagens WM_COMMAND especiais, com o código de notificação (como BN_CLICKED) e identificação compactada dentro de controle *wParam* e o identificador do controle no *lParam*. Observe que, como *wParam* e *lParam* são completos, não é possível passar dados adicionais, essas mensagens podem ser somente notificação simple. Por exemplo, na notificação BN_CLICKED, não é possível enviar informações sobre o local do cursor do mouse quando o botão foi clicado.  
  
 Quando controles do Windows 3. x é necessário para enviar uma mensagem de notificação que inclui dados adicionais, eles usam uma variedade de mensagens, com finalidade especial, incluindo WM_CTLCOLOR, WM_VSCROLL, WM_HSCROLL, WM_DRAWITEM, WM_MEASUREITEM, WM_COMPAREITEM, WM_DELETEITEM, WM _ CHARTOITEM, WM_VKEYTOITEM e assim por diante. Essas mensagens podem ser refletidas volta para o controle que enviou. Para obter mais informações, consulte [TN062: reflexão de mensagem para controles de Windows](../mfc/tn062-message-reflection-for-windows-controls.md).  
  
 **Mensagens de notificação em Win32**  
  
 Para controles que existiam no Windows 3.1, a API do Win32 usa a maior parte das mensagens de notificação que foram usadas no Windows 3. x. No entanto, Win32 também adiciona uma série de controles sofisticadas e complexas para aqueles com suporte no Windows 3. x. Com frequência, esses controles precisam enviar dados adicionais com suas mensagens de notificação. Em vez de adicionar um novo **WM _\***  de mensagem para cada nova notificação de que precisa de dados adicionais, os designers da API do Win32 optar por adicionar apenas uma mensagem WM_NOTIFY, que pode transmitir qualquer quantidade de dados adicionais em um forma padronizada.  
  
 Mensagens WM_NOTIFY contém a ID do controle enviando a mensagem em *wParam* e um ponteiro para uma estrutura em *lParam*. Essa estrutura é um **NMHDR** estrutura ou alguns maiores que tem um **NMHDR** estrutura como seu primeiro membro. Observe que, como o **NMHDR** membro é o primeiro, um ponteiro para essa estrutura pode ser usado como um ponteiro para um **NMHDR** ou como um ponteiro para a estrutura maior, dependendo de como você converter.  
  
 Na maioria dos casos, o ponteiro apontará para uma estrutura maior, e você precisa convertê-lo quando você usá-lo. Em apenas algumas notificações, como as notificações comuns (cujos nomes começam com **NM_**) e a ferramenta dica do controle TTN_SHOW e TTN_POP notificações, é um **NMHDR** estrutura realmente usada.  
  
 O **NMHDR** estrutura ou um membro inicial contém o identificador e a identificação do controle que está enviando a mensagem e o código de notificação (como TTN_SHOW). O formato da **NMHDR** estrutura é mostrada abaixo:  
  
```  
typedef struct tagNMHDR {  
    HWND hwndFrom;  
    UINT idFrom;  
    UINT code;  
} NMHDR;  
```  
  
 Para uma mensagem TTN_SHOW, o **código** membro será definido como TTN_SHOW.  
  
 A maioria das notificações transmitir um ponteiro para uma estrutura maior que contém um **NMHDR** estrutura como seu primeiro membro. Por exemplo, considere a estrutura usada por mensagem de notificação LVN_KEYDOWN do controle de exibição de lista, é enviada quando uma tecla é pressionada em um controle de exibição de lista. O ponteiro aponta para um **LV_KEYDOWN** estrutura, que é definida como mostrado abaixo:  
  
```  
typedef struct tagLV_KEYDOWN {  
    NMHDR hdr;     
    WORD wVKey;    
    UINT flags;    
} LV_KEYDOWN;  
```  
  
 Observe que, como o **NMHDR** membro é o primeiro nessa estrutura, o ponteiro é transmitido a mensagem de notificação pode ser convertido em um ponteiro para um **NMHDR** ou um ponteiro para um **LV_KEYDOWN** .  
  
 **Notificações comuns a todos os novos controles de Windows**  
  
 Algumas notificações são comuns a todos os novos controles de Windows. Essas notificações transmitir um ponteiro para um **NMHDR** estrutura.  
  
|Código de notificação|Enviado porque|  
|-----------------------|------------------|  
|NM_CLICK|Usuário clicou o botão esquerdo do mouse no controle|  
|NM_DBLCLK|Botão esquerdo do mouse clicado duas vezes de usuário no controle|  
|NM_RCLICK|Usuário clicou o botão direito do mouse no controle|  
|NM_RDBLCLK|Botão do usuário clica duas vezes direito do mouse no controle|  
|NM_RETURN|Usuário pressionou a tecla ENTER enquanto o controle tem foco de entrada|  
|NM_SETFOCUS|Controle tem foco de entrada|  
|NM_KILLFOCUS|Controle perdeu o foco de entrada|  
|NM_OUTOFMEMORY|Controle não foi possível concluir uma operação porque não havia memória suficiente disponível|  
  
##  <a name="_mfcnotes_on_notify.3a_.handling_wm_notify_messages_in_mfc_applications"></a> ON_NOTIFY: Manipulação de mensagens WM_NOTIFY em aplicativos MFC  
 A função `CWnd::OnNotify` manipula mensagens de notificação. Sua implementação padrão verifica o mapa de mensagem para manipuladores de notificação chamar. Em geral, você não substituir `OnNotify`. Em vez disso, você pode fornece uma função de manipulador e adicionar uma entrada de mapa de mensagem para esse manipulador para o mapa de mensagem da classe da janela do proprietário.  
  
 ClassWizard, por meio da folha de propriedades ClassWizard, crie a entrada de mapa de mensagens ON_NOTIFY e fornecer uma função de manipulador de esqueleto. Para obter mais informações sobre como usar ClassWizard para facilitar essa tarefa, consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md).  
  
 Macro ON_NOTIFY mapa de mensagem tem a seguinte sintaxe:  
  
```  
 
ON_NOTIFY(
wNotifyCode  ,  
id  ,
    memberFxn)  
 
```  
  
 onde os parâmetros em itálico são substituídos por:  
  
 *wNotifyCode*  
 O código para a mensagem de notificação deve ser tratado como LVN_KEYDOWN.  
  
 *id*  
 O identificador filho do controle para o qual a notificação é enviada.  
  
 *memberFxn*  
 A função de membro a ser chamado quando essa notificação é enviada.  
  
 A função de membro deve ser declarada com o seguinte protótipo:  
  
```  
 
afx_msg void  
memberFxn  
(NMHDR* 
pNotifyStruct  , LRESULT* result);

 
```  
  
## <a name="remarks"></a>Comentários  
 onde estão os parâmetros em itálico:  
  
 *pNotifyStruct*  
 Um ponteiro para a estrutura de notificação, conforme descrito na seção acima.  
  
 *resultado*  
 Um ponteiro para o código de resultado que você vai definir antes de retornar.  
  
## <a name="example"></a>Exemplo  
 Para especificar que você deseja que a função de membro `OnKeydownList1` para lidar com mensagens LVN_KEYDOWN o `CListCtrl` cuja ID é `IDC_LIST1`, você usaria ClassWizard para adicionar o seguinte ao mapa de mensagem:  
  
```  
ON_NOTIFY(LVN_KEYDOWN,
    IDC_LIST1,
    OnKeydownList1)  
```  
  
 No exemplo acima, a função fornecida pelo ClassWizard é:  
  
```  
void CMessageReflectionDlg::OnKeydownList1(NMHDR* pNMHDR, LRESULT* pResult)  
{  
    LV_KEYDOWN* pLVKeyDow = (LV_KEYDOWN*)pNMHDR; *// TODO: Add your control notification handler *//       code here  
 
 *pResult = 0;  
}  
```  
  
 Observe que ClassWizard fornece um indicador do tipo correto automaticamente. Você pode acessar a estrutura de notificação por meio de um *pNMHDR* ou *pLVKeyDow*.  
  
##  <a name="_mfcnotes_on_notify_range"></a> ON_NOTIFY_RANGE  
 Se você precisar processar a mensagem WM_NOTIFY mesmo para um conjunto de controles, você pode usar ON_NOTIFY_RANGE em vez de ON_NOTIFY. Por exemplo, você pode ter um conjunto de botões para o qual você deseja executar a mesma ação para uma determinada mensagem de notificação.  
  
 Quando você usa ON_NOTIFY_RANGE, você pode especificar um intervalo contíguo de identificadores de filho para manipular a mensagem de notificação especificando o início e término identificadores filho do intervalo.  
  
 ClassWizard não processa ON_NOTIFY_RANGE; para usá-lo, você precisa editar o mapa de mensagem por conta própria.  
  
 A entrada de mapa de mensagem e o protótipo de função para ON_NOTIFY_RANGE são da seguinte maneira:  
  
```  
 
ON_NOTIFY_RANGE(
wNotifyCode  ,   
id  ,   
idLast  ,
    memberFxn)  
 
```  
  
 onde os parâmetros em itálico são substituídos por:  
  
 *wNotifyCode*  
 O código para a mensagem de notificação deve ser tratado como LVN_KEYDOWN.  
  
 *id*  
 O identificador primeiro no intervalo contíguo de identificadores.  
  
 *idLast*  
 O último identificador no intervalo contíguo de identificadores.  
  
 *memberFxn*  
 A função de membro a ser chamado quando essa notificação é enviada.  
  
 A função de membro deve ser declarada com o seguinte protótipo:  
  
```  
 
afx_msg void  
memberFxn  
(UINT   
id  ,
    NMHDR* 
pNotifyStruct  ,
    LRESULT* result);

 
```  
  
## <a name="remarks"></a>Comentários  
 onde estão os parâmetros em itálico:  
  
 *id*  
 O identificador filho do controle que enviou a notificação.  
  
 *pNotifyStruct*  
 Um ponteiro para a estrutura de notificação, conforme descrito acima.  
  
 *resultado*  
 Um ponteiro para o código de resultado que você vai definir antes de retornar.  
  
##  <a name="_mfcnotes_tn061_on_notify_ex.2c_.on_notify_ex_range"></a> ON_NOTIFY_EX, ON_NOTIFY_EX_RANGE  
 Se você quiser mais de um objeto na notificação de roteamento para lidar com uma mensagem, você pode usar ON_NOTIFY_EX (ou ON_NOTIFY_EX_RANGE) em vez de ON_NOTIFY (ou ON_NOTIFY_RANGE). A única diferença entre o **EX** versão e a versão regular é chamado de função de membro para o **EX** versão retorna um **BOOL** que indica se ou não processamento de mensagens deve continuar. Retornando **FALSE** por essa função permite que você processe a mesma mensagem em mais de um objeto.  
  
 ClassWizard não trata ON_NOTIFY_EX ou ON_NOTIFY_EX_RANGE; Se você quiser usar um deles, você precisa editar o mapa de mensagem por conta própria.  
  
 A entrada de mapa de mensagem e o protótipo de função para ON_NOTIFY_EX e ON_NOTIFY_EX_RANGE são da seguinte maneira. Os significados dos parâmetros são as mesmas para não**EX** versões.  
  
```  
 
ON_NOTIFY_EX(
nCode  ,  
id  ,
    memberFxn) ON_NOTIFY_EX_RANGE(
wNotifyCode  ,   
id  ,   
idLast  ,
    memberFxn)  
 
```  
  
 O protótipo para ambas as opções acima é o mesmo:  
  
```  
 
afx_msg BOOL  
memberFxn  
(UINT   
id  ,
    NMHDR* 
pNotifyStruct  ,
    LRESULT* result);

 
```  
  
## <a name="remarks"></a>Comentários  
 Em ambos os casos, *id* contém o identificador filho do controle que enviou a notificação.  
  
 A função deve retornar **TRUE** se a mensagem de notificação foi tratada completamente ou **FALSE** se outros objetos no roteamento de comando devem ter a oportunidade de lidar com a mensagem.  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

