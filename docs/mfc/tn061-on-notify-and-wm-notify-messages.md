---
title: 'TN061: mensagens ON_NOTIFY e WM_NOTIFY'
ms.date: 06/28/2018
f1_keywords:
- ON_NOTIFY
- WM_NOTIFY
helpviewer_keywords:
- ON_NOTIFY_EX message [MFC]
- TN061
- ON_NOTIFY message [MFC]
- ON_NOTIFY_EX_RANGE message [MFC]
- ON_NOTIFY_RANGE message [MFC]
- notification messages
- WM_NOTIFY message
ms.assetid: 04a96dde-7049-41df-9954-ad7bb5587caf
ms.openlocfilehash: 74eb39a855da3ff3e6da7f14a76bf0804919826d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50658842"
---
# <a name="tn061-onnotify-and-wmnotify-messages"></a>TN061: mensagens ON_NOTIFY e WM_NOTIFY

> [!NOTE]
> A nota técnica a seguir não foi atualizada desde que foi incluído pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação online.

Essa observação técnica fornece informações básicas sobre a nova mensagem WM_NOTIFY e descreve a maneira recomendada (e mais comum) de manipulação de mensagens WM_NOTIFY em seu aplicativo do MFC.

**Mensagens de notificação em Windows 3. x**

No Windows 3. x, controles notificar seus pais de eventos como cliques do mouse, alterações no conteúdo e a seleção e a pintura de tela de fundo do controle, enviando uma mensagem para o pai. Notificações simples são enviadas como mensagens WM_COMMAND especiais, com o código de notificação (por exemplo, BN_CLICKED) e empacotada de identificação de controle *wParam* e o identificador do controle no *lParam*. Observe que, desde *wParam* e *lParam* são completo, não há nenhuma maneira de passar dados adicionais — essas mensagens podem ser somente notificação simple. Por exemplo, na notificação BN_CLICKED, não há nenhuma maneira de enviar informações sobre o local do cursor do mouse quando o botão foi clicado.

Quando os controles no Windows 3. x precisa enviar uma mensagem de notificação que inclui dados adicionais, eles usam uma variedade de mensagens de finalidade especial, incluindo WM_CTLCOLOR, WM_VSCROLL, mensagens WM_HSCROLL, WM_DRAWITEM, WM_MEASUREITEM, WM_COMPAREITEM, WM_DELETEITEM, WM _ CHARTOITEM, WM_VKEYTOITEM e assim por diante. Essas mensagens podem ser refletidas volta para o controle que enviou para eles. Para obter mais informações, consulte [TN062: reflexão de mensagem para controles de Windows](../mfc/tn062-message-reflection-for-windows-controls.md).

**Mensagens de notificação no Win32**

Para controles que existiam no Windows 3.1, a API do Win32 usa a maior parte das mensagens de notificação que foram usadas no Windows 3. x. No entanto, Win32 também adiciona uma série de controles sofisticados e complexos com suporte no Windows 3. x. Frequentemente, esses controles precisam enviar dados adicionais com suas mensagens de notificação. Em vez de adicionar um novo **WM _** <strong>\*</strong> de mensagem para cada nova notificação de que precisa de dados adicionais, os designers da API do Win32 optar por adicionar apenas uma mensagem WM_NOTIFY, que pode passar por nenhuma quantidade de dados adicionais de maneira padronizada.

Mensagens WM_NOTIFY contêm a ID do controle que está enviando a mensagem *wParam* e um ponteiro para uma estrutura *lParam*. Essa estrutura é uma **NMHDR** estrutura ou alguma estrutura maior que tem um **NMHDR** estrutura como seu primeiro membro. Observe que, como o **NMHDR** membro é o primeiro, um ponteiro para essa estrutura pode ser usado como um ponteiro para um **NMHDR** ou como um ponteiro para a estrutura maior, dependendo de como você convertê-lo.

Na maioria dos casos, o ponteiro apontará para uma estrutura maior e você precisará convertê-lo quando você usá-lo. Em apenas algumas notificações, como as notificações comuns (cujos nomes começam com **NM_**) e a ferramenta de dica do controle TTN_SHOW e TTN_POP notificações, é um **NMHDR** estrutura realmente usada.

O **NMHDR** estrutura ou um membro inicial contém o identificador e a ID do controle que está enviando a mensagem e o código de notificação (como TTN_SHOW). O formato do **NMHDR** estrutura é mostrada abaixo:

```cpp
typedef struct tagNMHDR {
    HWND hwndFrom;
    UINT idFrom;
    UINT code;
} NMHDR;
```

Para uma mensagem TTN_SHOW, o **código** membro seria definido como TTN_SHOW.

A maioria das notificações passarem um ponteiro para uma estrutura maior que contém um **NMHDR** estrutura como seu primeiro membro. Por exemplo, considere a estrutura usada por mensagem de notificação LVN_KEYDOWN do controle de exibição de lista, é enviada quando uma tecla é pressionada em um controle de exibição de lista. O ponteiro aponta para um **LV_KEYDOWN** estrutura, que é definida como mostrado abaixo:

```cpp
typedef struct tagLV_KEYDOWN {
    NMHDR hdr;
    WORD wVKey;
    UINT flags;
} LV_KEYDOWN;
```

Observe que, como o **NMHDR** membro é o primeiro nessa estrutura, o ponteiro é passado a mensagem de notificação pode ser convertido em um ponteiro para um **NMHDR** ou um ponteiro para um **LV_KEYDOWN** .

**Notificações comuns a todos os novos controles do Windows**

Algumas notificações são comuns a todos os novos controles do Windows. Essas notificações passarem um ponteiro para um **NMHDR** estrutura.

|Código de notificação|Enviado porque|
|-----------------------|------------------|
|NM_CLICK|Usuário clicou o botão esquerdo do mouse no controle|
|NM_DBLCLK|Botão esquerdo do mouse recebe um clique duplo de usuário no controle|
|NM_RCLICK|Usuário clicou o botão direito do mouse no controle|
|NM_RDBLCLK|Botão do usuário clicar duas vezes no botão direito do mouse no controle|
|NM_RETURN|Usuário pressionado a tecla ENTER enquanto o controle tem foco de entrada|
|NM_SETFOCUS|Controle tem foco de entrada|
|NM_KILLFOCUS|Controle perdeu o foco de entrada|
|NM_OUTOFMEMORY|Controle não foi possível concluir uma operação porque não havia memória suficiente disponível|

##  <a name="_mfcnotes_on_notify.3a_.handling_wm_notify_messages_in_mfc_applications"></a> ON_NOTIFY: Tratamento de mensagens WM_NOTIFY em aplicativos MFC

A função `CWnd::OnNotify` manipula mensagens de notificação. Sua implementação do padrão verifica o mapa de mensagem para manipuladores de notificação chamar. Em geral, você não substituir `OnNotify`. Em vez disso, você pode fornece uma função de manipulador e adicionar uma entrada de mapa de mensagem para esse manipulador para o mapa da mensagem da classe da janela do proprietário.

ClassWizard, por meio da folha de propriedades de ClassWizard, pode criar a entrada de mapa de mensagens ON_NOTIFY e fornecer uma função de manipulador de esqueleto. Para obter mais informações sobre como usar o ClassWizard para facilitar essa tarefa, consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md).

Macro ON_NOTIFY mapa de mensagem tem a seguinte sintaxe:

```cpp
ON_NOTIFY(wNotifyCode, id, memberFxn)
```

em que os parâmetros são:

*wNotifyCode*<br/>
O código para a mensagem de notificação ser manipulada, como LVN_KEYDOWN.

*id*<br/>
O identificador do filho do controle para o qual a notificação é enviada.

*memberFxn*<br/>
A função de membro a ser chamado quando essa notificação é enviada.

Sua função de membro deve ser declarada com o seguinte protótipo:

```cpp
afx_msg void memberFxn(NMHDR* pNotifyStruct, LRESULT* result);
```

em que os parâmetros são:

*pNotifyStruct*<br/>
Um ponteiro para a estrutura de notificação, conforme descrito na seção acima.

*resultado*<br/>
Um ponteiro para o código de resultado que você vai definir antes de retornar.

## <a name="example"></a>Exemplo

Para especificar que você deseja que a função de membro `OnKeydownList1` para lidar com mensagens LVN_KEYDOWN do `CListCtrl` cuja ID é `IDC_LIST1`, você usaria ClassWizard para adicionar o seguinte ao mapa de mensagem:

```cpp
ON_NOTIFY(LVN_KEYDOWN, IDC_LIST1, OnKeydownList1)
```

No exemplo acima, a função fornecida pelo ClassWizard é:

```cpp
void CMessageReflectionDlg::OnKeydownList1(NMHDR* pNMHDR, LRESULT* pResult)
{
    LV_KEYDOWN* pLVKeyDow = (LV_KEYDOWN*)pNMHDR;

    // TODO: Add your control notification handler
    //       code here

    *pResult = 0;
}
```

Observe que o ClassWizard fornece um ponteiro do tipo apropriado automaticamente. Você pode acessar a estrutura de notificação por meio de uma *pNMHDR* ou *pLVKeyDow*.

##  <a name="_mfcnotes_on_notify_range"></a> ON_NOTIFY_RANGE

Se você precisar processar a mensagem WM_NOTIFY mesma para um conjunto de controles, você pode usar ON_NOTIFY_RANGE em vez de ON_NOTIFY. Por exemplo, você pode ter um conjunto de botões para o qual você deseja executar a mesma ação para uma determinada mensagem de notificação.

Quando você usa ON_NOTIFY_RANGE, você pode especificar um intervalo contíguo de identificadores de filho para o qual manipular a mensagem de notificação, especificando o início e final identificadores filho do intervalo.

ClassWizard não processa ON_NOTIFY_RANGE; para usá-lo, você precisa editar o mapa de mensagem por conta própria.

A entrada de mapa de mensagem e o protótipo de função para ON_NOTIFY_RANGE são da seguinte maneira:

```cpp
ON_NOTIFY_RANGE(wNotifyCode, id, idLast, memberFxn)
```

em que os parâmetros são:

*wNotifyCode*<br/>
O código para a mensagem de notificação ser manipulada, como LVN_KEYDOWN.

*id*<br/>
O identificador primeiro no intervalo contíguo de identificadores.

*idLast*<br/>
O último identificador no intervalo contíguo de identificadores.

*memberFxn*<br/>
A função de membro a ser chamado quando essa notificação é enviada.

Sua função de membro deve ser declarada com o seguinte protótipo:

```cpp
afx_msg void memberFxn(UINT id, NMHDR* pNotifyStruct, LRESULT* result);
```

em que os parâmetros são:

*id*<br/>
O identificador do filho do controle que enviou a notificação.

*pNotifyStruct*<br/>
Um ponteiro para a estrutura de notificação, conforme descrito acima.

*resultado*<br/>
Um ponteiro para o código de resultado que você vai definir antes de retornar.

##  <a name="_mfcnotes_tn061_on_notify_ex.2c_.on_notify_ex_range"></a> ON_NOTIFY_EX, ON_NOTIFY_EX_RANGE

Se você quiser mais de um objeto na notificação de roteamento para lidar com uma mensagem, você pode usar ON_NOTIFY_EX (ou ON_NOTIFY_EX_RANGE) em vez de ON_NOTIFY (ou ON_NOTIFY_RANGE). A única diferença entre o **EX** versão e a versão regular é que a função de membro é chamada para o **EX** versão retorna um **BOOL** que indica se ou não processamento de mensagens deve continuar. Retornando **falsos** dessa função permite que você processe a mesma mensagem em mais de um objeto.

ClassWizard não trata ON_NOTIFY_EX ou ON_NOTIFY_EX_RANGE; Se você quiser usar qualquer uma delas, você precisa editar o mapa de mensagem por conta própria.

A entrada de mapa de mensagem e o protótipo de função para ON_NOTIFY_EX e ON_NOTIFY_EX_RANGE são da seguinte maneira. Os significados dos parâmetros são as mesmas para os não -**EX** versões.

```cpp
ON_NOTIFY_EX(nCode, id, memberFxn)
ON_NOTIFY_EX_RANGE(wNotifyCode, id, idLast, memberFxn)
```

O protótipo para ambas as opções acima é o mesmo:

```cpp
afx_msg BOOL memberFxn(UINT id, NMHDR* pNotifyStruct, LRESULT* result);
```

Em ambos os casos *id* contém o identificador do filho do controle que enviou a notificação.

A função deverá retornar **verdadeira** se a mensagem de notificação foi tratada completamente ou **falso** se outros objetos no roteamento de comando devem ter a oportunidade de manipular a mensagem.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
