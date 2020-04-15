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
ms.openlocfilehash: 845558dad6b9f6e820c759cb83fce2c6cbceaa0c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366593"
---
# <a name="tn061-on_notify-and-wm_notify-messages"></a>TN061: mensagens ON_NOTIFY e WM_NOTIFY

> [!NOTE]
> A nota técnica a seguir não foi atualizada desde que foi incluída pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizados ou incorretos. Para as últimas informações, recomenda-se que você pesquise o tópico de interesse no índice de documentação on-line.

Esta nota técnica fornece informações de fundo sobre a nova mensagem WM_NOTIFY e descreve a maneira recomendada (e mais comum) de lidar com mensagens WM_NOTIFY em seu aplicativo MFC.

**Mensagens de notificação no Windows 3.x**

No Windows 3.x, os controles notificam seus pais de eventos como cliques do mouse, alterações no conteúdo e seleção e controlam a pintura em segundo plano enviando uma mensagem para o pai. Notificações simples são enviadas como mensagens especiais WM_COMMAND, com o código de notificação (como BN_CLICKED) e o ID de controle embalado em *wParam* e a alça do controle em *lParam*. Observe que como *wParam* e *lParam* estão cheios, não há como passar nenhum dado adicional — essas mensagens podem ser apenas uma simples notificação. Por exemplo, na notificação BN_CLICKED, não há como enviar informações sobre a localização do cursor do mouse quando o botão foi clicado.

Quando os controles no Windows 3.x precisam enviar uma mensagem de notificação que inclua dados adicionais, eles usam uma variedade de mensagens de uso especial, incluindo WM_CTLCOLOR, WM_VSCROLL, WM_HSCROLL, WM_DRAWITEM, WM_MEASUREITEM, WM_COMPAREITEM, WM_DELETEITEM, WM_CHARTOITEM, WM_VKEYTOITEM e assim por diante. Essas mensagens podem ser refletidas de volta ao controle que as enviou. Para obter mais informações, consulte [TN062: Reflexão de mensagens para controles do Windows](../mfc/tn062-message-reflection-for-windows-controls.md).

**Mensagens de notificação no Win32**

Para controles que existiam no Windows 3.1, a API do Win32 usa a maioria das mensagens de notificação que foram usadas no Windows 3.x. No entanto, o Win32 também adiciona uma série de controles sofisticados e complexos aos suportados no Windows 3.x. Frequentemente, esses controles precisam enviar dados adicionais com suas mensagens de notificação. Em vez de adicionar uma nova mensagem **de WM_** <strong>\*</strong> para cada nova notificação que precise de dados adicionais, os designers da API Win32 optaram por adicionar apenas uma mensagem, WM_NOTIFY, que pode passar qualquer quantidade de dados adicionais de forma padronizada.

WM_NOTIFY mensagens contêm o ID do controle enviando a mensagem em *wParam* e um ponteiro para uma estrutura em *iParam*. Esta estrutura é uma estrutura **NMHDR** ou alguma estrutura maior que tem uma estrutura **NMHDR** como seu primeiro membro. Observe que, uma vez que o membro **NMHDR** é o primeiro, um ponteiro para esta estrutura pode ser usado como um ponteiro para um **NMHDR** ou como um ponteiro para a estrutura maior, dependendo de como você lançá-lo.

Na maioria dos casos, o ponteiro apontará para uma estrutura maior e você precisará lançá-la quando usá-la. Em apenas algumas notificações, como as notificações comuns (cujos nomes começam com **NM_)** e as notificações TTN_SHOW e TTN_POP do controle de ponta da ferramenta, é uma estrutura **NMHDR** realmente usada.

A estrutura ou membro inicial **do NMHDR** contém a alça e o ID do controle que envia a mensagem e o código de notificação (como TTN_SHOW). O formato da estrutura **NMHDR** é mostrado abaixo:

```cpp
typedef struct tagNMHDR {
    HWND hwndFrom;
    UINT idFrom;
    UINT code;
} NMHDR;
```

Para uma mensagem TTN_SHOW, o membro do **código** seria definido como TTN_SHOW.

A maioria das notificações passa um ponteiro para uma estrutura maior que contém uma estrutura **NMHDR** como seu primeiro membro. Por exemplo, considere a estrutura usada pela mensagem de notificação LVN_KEYDOWN do controle de exibição de lista, que é enviada quando uma chave é pressionada em um controle de exibição de lista. O ponteiro aponta para uma estrutura **LV_KEYDOWN,** que é definida como mostrado abaixo:

```cpp
typedef struct tagLV_KEYDOWN {
    NMHDR hdr;
    WORD wVKey;
    UINT flags;
} LV_KEYDOWN;
```

Observe que, uma vez que o membro **NMHDR** é o primeiro nesta estrutura, o ponteiro que você é passado na mensagem de notificação pode ser lançado para um ponteiro para um **NMHDR** ou um ponteiro para um **LV_KEYDOWN**.

**Notificações comuns a todos os novos controles do Windows**

Algumas notificações são comuns a todos os novos controles do Windows. Essas notificações passam um ponteiro para uma estrutura **NMHDR.**

|Código de notificação|Enviado porque|
|-----------------------|------------------|
|NM_CLICK|Usuário clicou no botão do mouse esquerdo no controle|
|NM_DBLCLK|Usuário clicou duas vezes no botão esquerdo do mouse no controle|
|NM_RCLICK|O usuário clicou no botão do mouse direito no controle|
|NM_RDBLCLK|Usuário clicou duas vezes no botão do mouse direito no controle|
|NM_RETURN|O usuário pressionou a tecla ENTER enquanto o controle tem foco de entrada|
|NM_SETFOCUS|Controle foi dado foco de entrada|
|NM_KILLFOCUS|Controle perdeu foco de entrada|
|NM_OUTOFMEMORY|O controle não pôde completar uma operação porque não havia memória suficiente disponível|

## <a name="on_notify-handling-wm_notify-messages-in-mfc-applications"></a><a name="_mfcnotes_on_notify.3a_.handling_wm_notify_messages_in_mfc_applications"></a>ON_NOTIFY: Manipulação de mensagens WM_NOTIFY em aplicativos MFC

A `CWnd::OnNotify` função lida com mensagens de notificação. Sua implementação padrão verifica o mapa de mensagens para que os manipuladores de notificação chamem. Em geral, você não `OnNotify`se sobrepor. Em vez disso, você fornece uma função de manipulador e adiciona uma entrada de mapa de mensagem para esse manipulador no mapa de mensagens da classe da janela do proprietário.

O ClassWizard, através da folha de propriedades ClassWizard, pode criar a entrada ON_NOTIFY mapa de mensagem e fornecer-lhe uma função de manipulador esqueleto. Para obter mais informações sobre como usar o ClassWizard para facilitar isso, consulte ['Mapeamento de mensagens' para funções](../mfc/reference/mapping-messages-to-functions.md).

A ON_NOTIFY macro mapa de mensagem tem a seguinte sintaxe:

```cpp
ON_NOTIFY(wNotifyCode, id, memberFxn)
```

em que os parâmetros são:

*wNotifyCode*<br/>
O código para a mensagem de notificação a ser tratada, como LVN_KEYDOWN.

*id*<br/>
O identificador infantil do controle para o qual a notificação é enviada.

*Memberfxn*<br/>
A função de membro a ser chamada quando esta notificação é enviada.

Sua função de membro deve ser declarada com o seguinte protótipo:

```cpp
afx_msg void memberFxn(NMHDR* pNotifyStruct, LRESULT* result);
```

em que os parâmetros são:

*pNotificarStruct*<br/>
Um ponteiro para a estrutura de notificação, conforme descrito na seção acima.

*Resultado*<br/>
Um ponteiro para o código de resultado que você definirá antes de retornar.

## <a name="example"></a>Exemplo

Para especificar que deseja `OnKeydownList1` que a função `CListCtrl` de membro `IDC_LIST1`manuseie LVN_KEYDOWN mensagens do qual o ID é, você usaria o ClassWizard para adicionar o seguinte ao seu mapa de mensagens:

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

Observe que o ClassWizard fornece um ponteiro do tipo adequado automaticamente. Você pode acessar a estrutura de notificação através de *pNMHDR* ou *pLVKeyDow*.

## <a name="on_notify_range"></a><a name="_mfcnotes_on_notify_range"></a>On_notify_range

Se você precisar processar a mesma mensagem WM_NOTIFY para um conjunto de controles, você pode usar ON_NOTIFY_RANGE em vez de ON_NOTIFY. Por exemplo, você pode ter um conjunto de botões para os quais deseja executar a mesma ação para uma determinada mensagem de notificação.

Quando você usa ON_NOTIFY_RANGE, você especifica uma gama contígua de identificadores de filho para os quais lidar com a mensagem de notificação especificando os identificadores de início e final do filho do intervalo.

O ClassWizard não lida com ON_NOTIFY_RANGE; para usá-lo, você precisa editar seu mapa de mensagem você mesmo.

O protótipo de entrada e função do mapa de mensagem para ON_NOTIFY_RANGE são os seguintes:

```cpp
ON_NOTIFY_RANGE(wNotifyCode, id, idLast, memberFxn)
```

em que os parâmetros são:

*wNotifyCode*<br/>
O código para a mensagem de notificação a ser tratada, como LVN_KEYDOWN.

*id*<br/>
O primeiro identificador na gama contígua de identificadores.

*idLast*<br/>
O último identificador na faixa contígua de identificadores.

*Memberfxn*<br/>
A função de membro a ser chamada quando esta notificação é enviada.

Sua função de membro deve ser declarada com o seguinte protótipo:

```cpp
afx_msg void memberFxn(UINT id, NMHDR* pNotifyStruct, LRESULT* result);
```

em que os parâmetros são:

*id*<br/>
O identificador infantil do controle que enviou a notificação.

*pNotificarStruct*<br/>
Um ponteiro para a estrutura de notificação, como descrito acima.

*Resultado*<br/>
Um ponteiro para o código de resultado que você definirá antes de retornar.

## <a name="on_notify_ex-on_notify_ex_range"></a><a name="_mfcnotes_tn061_on_notify_ex.2c_.on_notify_ex_range"></a>ON_NOTIFY_EX ON_NOTIFY_EX_RANGE.

Se você quiser mais de um objeto no roteamento de notificação para lidar com uma mensagem, você pode usar ON_NOTIFY_EX (ou ON_NOTIFY_EX_RANGE) em vez de ON_NOTIFY (ou ON_NOTIFY_RANGE). A única diferença entre a versão **EX** e a versão regular é que a função de membro chamada para a versão **EX** retorna um **BOOL** que indica se o processamento de mensagens deve ou não continuar. O retorno de **FALSE** desta função permite processar a mesma mensagem em mais de um objeto.

O ClassWizard não lida com ON_NOTIFY_EX ou ON_NOTIFY_EX_RANGE; se você quiser usar qualquer um deles, você precisa editar seu mapa de mensagem você mesmo.

O protótipo de entrada e função do mapa de mensagens para ON_NOTIFY_EX e ON_NOTIFY_EX_RANGE são os seguintes. Os significados dos parâmetros são os mesmos das versões**não-EX.**

```cpp
ON_NOTIFY_EX(nCode, id, memberFxn)
ON_NOTIFY_EX_RANGE(wNotifyCode, id, idLast, memberFxn)
```

O protótipo para ambos os acima é o mesmo:

```cpp
afx_msg BOOL memberFxn(UINT id, NMHDR* pNotifyStruct, LRESULT* result);
```

Em ambos os casos, a *identificação* da criança mantém o identificador da criança do controle que enviou a notificação.

Sua função deve retornar **TRUE** se a mensagem de notificação tiver sido completamente manuseada ou **FALSA** se outros objetos no roteamento de comando tiverem a chance de lidar com a mensagem.

## <a name="see-also"></a>Confira também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
