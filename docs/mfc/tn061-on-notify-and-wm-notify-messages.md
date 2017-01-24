---
title: "TN061: mensagens ON_NOTIFY e WM_NOTIFY | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "ON_NOTIFY"
  - "WM_NOTIFY"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ON_NOTIFY_EX (mensagem)"
  - "TN061"
  - "ON_NOTIFY (mensagem)"
  - "ON_NOTIFY_EX_RANGE (mensagem)"
  - "ON_NOTIFY_RANGE (mensagem)"
  - "mensagens de notificação"
  - "WM_NOTIFY (mensagem)"
ms.assetid: 04a96dde-7049-41df-9954-ad7bb5587caf
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN061: mensagens ON_NOTIFY e WM_NOTIFY
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  Esta nota técnica não foi atualizada desde que ele foi incluído pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação on\-line.  
  
 Esta nota técnica fornece informações básicas sobre o novo **WM\_NOTIFY** mensagem e descreve a maneira recomendada \(e mais comum\) de tratamento de **WM\_NOTIFY** mensagens em seu aplicativo do MFC.  
  
 **Mensagens de notificação do Windows 3. x**  
  
 No Windows 3. x, controles notificar seus pais de eventos como cliques de mouse, alterações no conteúdo e a seleção e a pintura de plano de fundo do controle, enviando uma mensagem para o pai. Simples notificações são enviadas como especiais **WM\_COMMAND** mensagens, com o código de notificação \(como **BN\_CLICKED**\) e controlar ID empacotado em `wParam` e o identificador do controle em `lParam`. Observe que, como `wParam` e `lParam` são completos, não há nenhuma maneira de passar dados adicionais — essas mensagens podem ser somente notificação simple. Por exemplo, no **BN\_CLICKED** notificação, não é possível enviar informações sobre o local do cursor do mouse quando o botão for clicado.  
  
 Quando controles do Windows 3. x precisam enviar uma mensagem de notificação que inclui dados adicionais, eles usam uma variedade de mensagens de finalidade especial, incluindo `WM_CTLCOLOR`, `WM_VSCROLL`, `WM_HSCROLL`, `WM_DRAWITEM`, `WM_MEASUREITEM`, `WM_COMPAREITEM`, `WM_DELETEITEM`, `WM_CHARTOITEM`, `WM_VKEYTOITEM`, e assim por diante. Essas mensagens podem ser refletidas volta para o controle que enviou a eles. Para obter mais informações, consulte [TN062: reflexão de mensagem para controles de Windows](../mfc/tn062-message-reflection-for-windows-controls.md).  
  
 **Mensagens de notificação no Win32**  
  
 Para controles que existiam no Windows 3.1, a API do Win32 usa a maior parte das mensagens de notificação que foram usadas no Windows 3. x. No entanto, Win32 também adiciona uma série de controles sofisticados e complexos para aqueles com suporte no Windows 3. x. Freqüentemente, esses controles precisam enviar dados adicionais com suas mensagens de notificação. Em vez de adicionar um novo **WM \_ \*** mensagem para cada nova notificação de que precisa de dados adicionais, os designers da API do Win32 decidiu adicionar uma única mensagem, **WM\_NOTIFY**, que pode passar qualquer quantidade de dados adicionais de maneira padronizada.  
  
 **WM\_NOTIFY** mensagens contêm a ID do controle enviando a mensagem `wParam` e um ponteiro para uma estrutura em `lParam`. Essa estrutura é um **NMHDR** estrutura ou alguns maiores que tem um **NMHDR** estrutura como seu primeiro membro. Observe que, como o **NMHDR** membro é o primeiro, um ponteiro para essa estrutura pode ser usado como um ponteiro para um **NMHDR** ou como um ponteiro para a estrutura maior, dependendo de como você convertê\-lo.  
  
 Na maioria dos casos, o ponteiro apontará para uma estrutura maior e você precisará convertê\-lo quando você usá\-lo. Em apenas algumas notificações, como as notificações comuns \(cujos nomes começam com **NM\_**\) e o controle de dica de ferramenta **TTN\_SHOW** e **TTN\_POP** notificações, é um **NMHDR** estrutura realmente usada.  
  
 O **NMHDR** estrutura ou membro inicial contém o identificador e a ID do controle enviando a mensagem e o código de notificação \(como **TTN\_SHOW**\). O formato do **NMHDR** estrutura é mostrada abaixo:  
  
```  
typedef struct tagNMHDR {  
    HWND hwndFrom;  
    UINT idFrom;  
    UINT code;  
} NMHDR;  
```  
  
 Para uma **TTN\_SHOW** mensagem, o **código** membro deve ser definido como **TTN\_SHOW**.  
  
 A maioria das notificações passarem um ponteiro para uma estrutura maior que contém um **NMHDR** estrutura como seu primeiro membro. Por exemplo, considere a estrutura usada pelo controle de exibição de lista **LVN\_KEYDOWN** mensagem de notificação, que é enviada quando uma tecla é pressionada em um controle de exibição de lista. O ponteiro aponta para um **LV\_KEYDOWN** estrutura, que é definida como mostrado abaixo:  
  
```  
typedef struct tagLV_KEYDOWN {  
    NMHDR hdr;     
    WORD wVKey;    
    UINT flags;    
} LV_KEYDOWN;  
```  
  
 Observe que, como o **NMHDR** primeiro nessa estrutura é membro, o ponteiro é passado a mensagem de notificação pode ser convertido em um ponteiro para um **NMHDR** ou um ponteiro para um **LV\_KEYDOWN**.  
  
 **Notificações comuns a todos os novos controles do Windows**  
  
 Algumas notificações são comuns a todos os novos controles do Windows. Essas notificações passarem um ponteiro para um **NMHDR** estrutura.  
  
|Código de notificação|Enviado porque|  
|---------------------------|--------------------|  
|**NM\_CLICK**|Usuário clicou o botão esquerdo do mouse no controle|  
|**NM\_DBLCLK**|Botão do usuário clicado duas vezes esquerdo do mouse no controle|  
|**NM\_RCLICK**|Usuário clicou o botão direito do mouse no controle|  
|**NM\_RDBLCLK**|Botão do usuário clica duas vezes direito do mouse no controle|  
|**NM\_RETURN**|Pressionada a tecla ENTER enquanto o controle tem o foco de entrada do usuário|  
|**NM\_SETFOCUS**|Controle tem foco de entrada|  
|**NM\_KILLFOCUS**|Controle perdeu o foco de entrada|  
|**NM\_OUTOFMEMORY**|Controle não foi possível concluir uma operação porque não havia memória suficiente disponível|  
  
##  <a name="_mfcnotes_on_notify.3a_.handling_wm_notify_messages_in_mfc_applications"></a> ON\_NOTIFY: Manipulação de mensagens WM\_NOTIFY em aplicativos MFC  
 A função `CWnd::OnNotify` manipula mensagens de notificação. A implementação padrão verifica o mapa da mensagem para manipuladores de notificação chamar. Em geral, você não substituir `OnNotify`. Em vez disso, você fornece uma função de manipulador e adicionar uma entrada de mapa da mensagem para esse manipulador para o mapa da mensagem da classe da janela do proprietário.  
  
 ClassWizard, via a folha de propriedades de ClassWizard, pode criar o `ON_NOTIFY` entrada de mapa de mensagem e fornecer uma função de manipulador de esqueleto. Para obter mais informações sobre como usar ClassWizard para facilitar essa tarefa, consulte [Mapeando mensagens para funções](../Topic/Mapping%20Messages%20to%20Functions.md).  
  
 O `ON_NOTIFY` macros de mapa de mensagem tem a seguinte sintaxe:  
  
```  
  
ON_NOTIFY(  
wNotifyCode  
,  
id  
,  
memberFxn  
)  
  
```  
  
 onde os parâmetros em itálico são substituídos por:  
  
 `wNotifyCode`  
 O código para a mensagem de notificação a ser manipulada, como **LVN\_KEYDOWN**.  
  
 `id`  
 O identificador filho do controle para o qual a notificação é enviada.  
  
 `memberFxn`  
 A função de membro a ser chamado quando essa notificação é enviada.  
  
 A função de membro deve ser declarada com o seguinte protótipo:  
  
```  
  
afx_msg void  
memberFxn  
( NMHDR *  
pNotifyStruct  
, LRESULT *  
result  
);  
  
```  
  
## Comentários  
 onde estão os parâmetros em itálico:  
  
 `pNotifyStruct`  
 Um ponteiro para a estrutura de notificação, conforme descrito na seção acima.  
  
 *resultado*  
 Um ponteiro para o código de resultado que você vai configurar antes de retornar.  
  
## Exemplo  
 Para especificar que você deseja que a função de membro `OnKeydownList1` para tratar **LVN\_KEYDOWN** mensagens do `CListCtrl` cuja ID é `IDC_LIST1`, você usaria ClassWizard para adicionar o seguinte ao mapa de mensagem:  
  
```  
ON_NOTIFY( LVN_KEYDOWN, IDC_LIST1, OnKeydownList1 )  
```  
  
 No exemplo acima, a função fornecida pelo ClassWizard é:  
  
```  
void CMessageReflectionDlg::OnKeydownList1(NMHDR* pNMHDR, LRESULT* pResult)  
{  
   LV_KEYDOWN* pLVKeyDow = (LV_KEYDOWN*)pNMHDR;  
   // TODO: Add your control notification handler  
   //       code here  
  
   *pResult = 0;  
}  
```  
  
 Observe que ClassWizard fornece automaticamente um ponteiro do tipo adequado. Você pode acessar a estrutura de notificação por meio `pNMHDR` ou `pLVKeyDow`.  
  
##  <a name="_mfcnotes_on_notify_range"></a> ON\_NOTIFY\_RANGE  
 Se você precisar processar o mesmo **WM\_NOTIFY** mensagem para um conjunto de controles, você pode usar **ON\_NOTIFY\_RANGE** em vez de `ON_NOTIFY`. Por exemplo, você pode ter um conjunto de botões para o qual você deseja executar a mesma ação para uma determinada mensagem de notificação.  
  
 Quando você usa **ON\_NOTIFY\_RANGE**, especifique um intervalo contíguo de identificadores de filho para manipular a mensagem de notificação especificando o início e término identificadores filho do intervalo.  
  
 Não processa ClassWizard **ON\_NOTIFY\_RANGE**; usá\-lo, você precisa editar o mapa de mensagem por conta própria.  
  
 O protótipo de entrada e a função de mapa de mensagem para **ON\_NOTIFY\_RANGE** são os seguintes:  
  
```  
  
ON_NOTIFY_RANGE(   
wNotifyCode  
,   
id  
,   
idLast  
,   
memberFxn  
 )  
  
```  
  
 onde os parâmetros em itálico são substituídos por:  
  
 `wNotifyCode`  
 O código para a mensagem de notificação a ser manipulada, como **LVN\_KEYDOWN**.  
  
 `id`  
 O identificador primeiro no intervalo contíguo de identificadores.  
  
 `idLast`  
 O último identificador no intervalo contíguo de identificadores.  
  
 `memberFxn`  
 A função de membro a ser chamado quando essa notificação é enviada.  
  
 A função de membro deve ser declarada com o seguinte protótipo:  
  
```  
  
afx_msg void  
memberFxn  
( UINT   
id  
, NMHDR *  
pNotifyStruct  
, LRESULT *  
result  
);  
  
```  
  
## Comentários  
 onde estão os parâmetros em itálico:  
  
 `id`  
 O identificador filho do controle que enviou a notificação.  
  
 `pNotifyStruct`  
 Um ponteiro para a estrutura de notificação, conforme descrito acima.  
  
 *resultado*  
 Um ponteiro para o código de resultado que você vai configurar antes de retornar.  
  
##  <a name="_mfcnotes_tn061_on_notify_ex.2c_.on_notify_ex_range"></a> ON\_NOTIFY\_EX, ON\_NOTIFY\_EX\_RANGE  
 Se você quiser mais de um objeto na notificação de roteamento para lidar com uma mensagem, você pode usar **ON\_NOTIFY\_EX** \(ou **ON\_NOTIFY\_EX\_RANGE**\) em vez de `ON_NOTIFY` \(ou **ON\_NOTIFY\_RANGE**\). A única diferença entre o **EX** versão e a versão comum é que a função de membro chamada para o **EX** versão retorna um **BOOL** que indica se ou não o processamento da mensagem deve continuar. Retornando **FALSE** por essa função permite que você processe a mesma mensagem em mais de um objeto.  
  
 Não processa ClassWizard **ON\_NOTIFY\_EX** ou **ON\_NOTIFY\_EX\_RANGE**; se você quiser usar uma delas, você precisa editar o mapa de mensagem por conta própria.  
  
 O protótipo de entrada e a função de mapa de mensagem para **ON\_NOTIFY\_EX** e **ON\_NOTIFY\_EX\_RANGE** são da seguinte maneira. Os significados dos parâmetros são as mesmas para não**EX** versões.  
  
```  
  
ON_NOTIFY_EX(  
nCode  
,  
id  
,  
memberFxn  
) ON_NOTIFY_EX_RANGE(   
wNotifyCode  
,   
id  
,   
idLast  
,  
memberFxn  
 )  
  
```  
  
 O protótipo para ambas as condições acima é o mesmo:  
  
```  
  
afx_msg BOOL  
memberFxn  
( UINT   
id  
, NMHDR *  
pNotifyStruct  
, LRESULT *  
result  
);  
  
```  
  
## Comentários  
 Em ambos os casos, `id` contém o identificador filho do controle que enviou a notificação.  
  
 A função deve retornar **TRUE** se a mensagem de notificação foi tratada completamente ou **FALSE** se outros objetos no roteamento de comando devem ter a oportunidade de manipular a mensagem.  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)