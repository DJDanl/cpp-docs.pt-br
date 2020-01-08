---
title: 'TN061: mensagens ON_NOTIFY e WM_NOTIFY'
ms.date: 06/28/2018
helpviewer_keywords:
- ON_NOTIFY_EX message [MFC]
- TN061
- ON_NOTIFY message [MFC]
- ON_NOTIFY_EX_RANGE message [MFC]
- ON_NOTIFY_RANGE message [MFC]
- notification messages
- WM_NOTIFY message
ms.assetid: 04a96dde-7049-41df-9954-ad7bb5587caf
ms.openlocfilehash: aa1efb628ee45be3dfaee320cf64c4b2cbb91f04
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75302231"
---
# <a name="tn061-on_notify-and-wm_notify-messages"></a>TN061: mensagens ON_NOTIFY e WM_NOTIFY

> [!NOTE]
> A observação técnica a seguir não foi atualizada desde que foi incluída pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizados ou incorretos. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice de documentação online.

Esta nota técnica fornece informações básicas sobre a nova mensagem de WM_NOTIFY e descreve a maneira recomendada (e mais comum) de lidar com WM_NOTIFY mensagens em seu aplicativo MFC.

**Mensagens de notificação no Windows 3. x**

No Windows 3. x, os controles notificam seus pais sobre eventos, como cliques do mouse, alterações no conteúdo e na seleção, e controlam a pintura em segundo plano enviando uma mensagem para o pai. As notificações simples são enviadas como mensagens WM_COMMAND especiais, com o código de notificação (como BN_CLICKED) e a ID de controle empacotada em *wParam* e o identificador do controle em *lParam*. Observe que, como *wParam* e *lParam* estão cheios, não há como passar dados adicionais — essas mensagens podem ser apenas uma notificação simples. Por exemplo, na notificação de BN_CLICKED, não há como enviar informações sobre o local do cursor do mouse quando o botão foi clicado.

Quando os controles no Windows 3. x precisam enviar uma mensagem de notificação que inclui dados adicionais, eles usam uma variedade de mensagens de finalidade especial, incluindo WM_CTLCOLOR, WM_VSCROLL, WM_HSCROLL, WM_DRAWITEM, WM_MEASUREITEM, WM_COMPAREITEM, WM_DELETEITEM, WM_ CHARTOITEM, WM_VKEYTOITEM e assim por diante. Essas mensagens podem ser refletidas de volta para o controle que as enviou. Para obter mais informações, consulte [TN062: Reflection de mensagem para controles do Windows](../mfc/tn062-message-reflection-for-windows-controls.md).

**Mensagens de notificação no Win32**

Para controles que existiam no Windows 3,1, a API do Win32 usa a maioria das mensagens de notificação que foram usadas no Windows 3. x. No entanto, o Win32 também adiciona vários controles sofisticados e complexos àqueles com suporte no Windows 3. x. Frequentemente, esses controles precisam enviar dados adicionais com suas mensagens de notificação. Em vez de adicionar um novo **WM_** <strong>\*</strong> mensagem para cada nova notificação que precisa de dados adicionais, os designers da API do Win32 optam por adicionar apenas uma mensagem, WM_NOTIFY, que pode passar qualquer quantidade de dados adicionais de maneira padronizada.

WM_NOTIFY mensagens contêm a ID do controle que envia a mensagem em *wParam* e um ponteiro para uma estrutura em *lParam*. Essa estrutura é uma estrutura **NMHDR** ou alguma estrutura maior que tem uma estrutura **NMHDR** como seu primeiro membro. Observe que, como o membro **NMHDR** é primeiro, um ponteiro para essa estrutura pode ser usado como um ponteiro para um **NMHDR** ou como um ponteiro para a estrutura maior, dependendo de como você o converte.

Na maioria dos casos, o ponteiro apontará para uma estrutura maior e você precisará convertê-lo ao usá-lo. Em apenas algumas notificações, como as notificações comuns (cujos nomes começam com **NM_** ) e as notificações de TTN_SHOW e TTN_POP do controle de dica de ferramenta, é uma estrutura **NMHDR** realmente usada.

A estrutura **NMHDR** ou o membro inicial contém o identificador e a ID do controle que envia a mensagem e o código de notificação (como TTN_SHOW). O formato da estrutura **NMHDR** é mostrado abaixo:

```cpp
typedef struct tagNMHDR {
    HWND hwndFrom;
    UINT idFrom;
    UINT code;
} NMHDR;
```

Para uma mensagem TTN_SHOW, o membro do **código** seria definido como TTN_SHOW.

A maioria das notificações passa um ponteiro para uma estrutura maior que contém uma estrutura **NMHDR** como seu primeiro membro. Por exemplo, considere a estrutura usada pela LVN_KEYDOWN mensagem de notificação do controle de exibição de lista, que é enviada quando uma tecla é pressionada em um controle de exibição de lista. O ponteiro aponta para uma estrutura de **LV_KEYDOWN** , que é definida conforme mostrado abaixo:

```cpp
typedef struct tagLV_KEYDOWN {
    NMHDR hdr;
    WORD wVKey;
    UINT flags;
} LV_KEYDOWN;
```

Observe que, como o membro **NMHDR** é primeiro nessa estrutura, o ponteiro que você passa na mensagem de notificação pode ser convertido em um ponteiro para um **NMHDR** ou um ponteiro para um **LV_KEYDOWN**.

**Notificações comuns a todos os novos controles do Windows**

Algumas notificações são comuns a todos os novos controles do Windows. Essas notificações passam um ponteiro para uma estrutura **NMHDR** .

|Código de notificação|Enviado porque|
|-----------------------|------------------|
|NM_CLICK|O usuário clicou com o botão esquerdo do mouse no controle|
|NM_DBLCLK|O usuário clicou duas vezes com o botão esquerdo do mouse no controle|
|NM_RCLICK|O usuário clicou com o botão direito do mouse no controle|
|NM_RDBLCLK|O usuário clicou duas vezes com o botão direito do mouse no controle|
|NM_RETURN|O usuário pressionou a tecla ENTER enquanto o controle tem foco de entrada|
|NM_SETFOCUS|O controle recebeu o foco de entrada|
|NM_KILLFOCUS|O controle perdeu o foco de entrada|
|NM_OUTOFMEMORY|O controle não pôde concluir uma operação porque não havia memória suficiente disponível|

##  <a name="_mfcnotes_on_notify.3a_.handling_wm_notify_messages_in_mfc_applications"></a>ON_NOTIFY: tratamento de mensagens WM_NOTIFY em aplicativos MFC

A função `CWnd::OnNotify` lida com mensagens de notificação. Sua implementação padrão verifica o mapa de mensagens para que os manipuladores de notificação chamem. Em geral, você não substitui `OnNotify`. Em vez disso, você fornece uma função de manipulador e adiciona uma entrada de mapa de mensagem para esse manipulador ao mapa de mensagens da classe da sua janela do proprietário.

ClassWizard, por meio da folha de propriedades ClassWizard, pode criar a ON_NOTIFY entrada de mapa de mensagens e fornecer uma função de manipulador esqueleto. Para obter mais informações sobre como usar o ClassWizard para tornar isso mais fácil, consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md).

A macro ON_NOTIFY mapa de mensagens tem a seguinte sintaxe:

```cpp
ON_NOTIFY(wNotifyCode, id, memberFxn)
```

em que os parâmetros são:

*wNotifyCode*<br/>
O código para a mensagem de notificação a ser manipulada, como LVN_KEYDOWN.

*id*<br/>
O identificador filho do controle para o qual a notificação é enviada.

*memberFxn*<br/>
A função de membro a ser chamada quando essa notificação é enviada.

Sua função de membro deve ser declarada com o seguinte protótipo:

```cpp
afx_msg void memberFxn(NMHDR* pNotifyStruct, LRESULT* result);
```

em que os parâmetros são:

*pNotifyStruct*<br/>
Um ponteiro para a estrutura de notificação, conforme descrito na seção acima.

*resultado*<br/>
Um ponteiro para o código de resultado que você definirá antes de retornar.

## <a name="example"></a>Exemplo

Para especificar que você deseja que a função membro `OnKeydownList1` para manipular LVN_KEYDOWN mensagens do `CListCtrl` cuja ID é `IDC_LIST1`da, você usaria ClassWizard para adicionar o seguinte ao seu mapa de mensagens:

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

Observe que ClassWizard fornece um ponteiro do tipo apropriado automaticamente. Você pode acessar a estrutura de notificação por meio de *pNMHDR* ou *pLVKeyDow*.

##  <a name="_mfcnotes_on_notify_range"></a> ON_NOTIFY_RANGE

Se você precisar processar a mesma WM_NOTIFY mensagem para um conjunto de controles, poderá usar ON_NOTIFY_RANGE em vez de ON_NOTIFY. Por exemplo, você pode ter um conjunto de botões para os quais deseja executar a mesma ação para uma determinada mensagem de notificação.

Ao usar ON_NOTIFY_RANGE, você especifica um intervalo contíguo de identificadores filho para o qual tratar a mensagem de notificação especificando os identificadores filho inicial e final do intervalo.

ClassWizard não manipula ON_NOTIFY_RANGE; para usá-lo, você precisa editar seu mapa de mensagens por conta própria.

A entrada de mapa de mensagem e o protótipo de função para ON_NOTIFY_RANGE são os seguintes:

```cpp
ON_NOTIFY_RANGE(wNotifyCode, id, idLast, memberFxn)
```

em que os parâmetros são:

*wNotifyCode*<br/>
O código para a mensagem de notificação a ser manipulada, como LVN_KEYDOWN.

*id*<br/>
O primeiro identificador no intervalo contíguo de identificadores.

*idLast*<br/>
O último identificador no intervalo contíguo de identificadores.

*memberFxn*<br/>
A função de membro a ser chamada quando essa notificação é enviada.

Sua função de membro deve ser declarada com o seguinte protótipo:

```cpp
afx_msg void memberFxn(UINT id, NMHDR* pNotifyStruct, LRESULT* result);
```

em que os parâmetros são:

*id*<br/>
O identificador filho do controle que enviou a notificação.

*pNotifyStruct*<br/>
Um ponteiro para a estrutura de notificação, conforme descrito acima.

*resultado*<br/>
Um ponteiro para o código de resultado que você definirá antes de retornar.

##  <a name="_mfcnotes_tn061_on_notify_ex.2c_.on_notify_ex_range"></a> ON_NOTIFY_EX, ON_NOTIFY_EX_RANGE

Se desejar que mais de um objeto no roteamento de notificação manipule uma mensagem, você poderá usar ON_NOTIFY_EX (ou ON_NOTIFY_EX_RANGE) em vez de ON_NOTIFY (ou ON_NOTIFY_RANGE). A única diferença entre a versão **ex** e a versão regular é que a função de membro chamada para a versão **ex** retorna um **bool** que indica se o processamento de mensagens deve ou não continuar. Retornar **false** dessa função permite processar a mesma mensagem em mais de um objeto.

ClassWizard não lida com ON_NOTIFY_EX ou ON_NOTIFY_EX_RANGE; Se você quiser usar qualquer um deles, precisará editar seu mapa de mensagens por conta própria.

A entrada de mapa de mensagem e o protótipo de função para ON_NOTIFY_EX e ON_NOTIFY_EX_RANGE são os seguintes. Os significados dos parâmetros são os mesmos para as versões não-**ex** .

```cpp
ON_NOTIFY_EX(nCode, id, memberFxn)
ON_NOTIFY_EX_RANGE(wNotifyCode, id, idLast, memberFxn)
```

O protótipo para ambos os itens acima é o mesmo:

```cpp
afx_msg BOOL memberFxn(UINT id, NMHDR* pNotifyStruct, LRESULT* result);
```

Em ambos os casos, a *ID* contém o identificador filho do controle que enviou a notificação.

Sua função deve retornar **true** se a mensagem de notificação tiver sido completamente manipulada ou **falsa** se outros objetos no roteamento de comandos tiverem a oportunidade de lidar com a mensagem.

## <a name="see-also"></a>Veja também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
