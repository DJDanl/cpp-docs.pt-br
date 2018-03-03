---
title: "TN062: Reflexão para controles do Windows da mensagem | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.controls.messages
dev_langs:
- C++
helpviewer_keywords:
- ON_WM_VKEYTOITEM_REFLECT macro [MFC]
- ON_WM_DRAWITEM_REFLECT macro [MFC]
- ON_WM_VSCROLL_REFLECT macro [MFC]
- ON_NOTIFY_REFLECT message [MFC]
- ON_CONTROL_REFLECT_EX macro [MFC]
- ON_UPDATE_COMMAND_UI_REFLECT macro [MFC]
- ON_NOTIFY_REFLECT_EX message [MFC]
- ON_WM_HSCROLL_REFLECT macro [MFC]
- message reflection [MFC]
- ON_WM_COMPAREITEM_REFLECT macro [MFC]
- ON_WM_MEASUREITEM_REFLECT macro [MFC]
- ON_NOTIFY message [MFC]
- WM_COMMAND [MFC]
- WM_CTLCOLOR message [MFC]
- TN062 [MFC]
- ON_WM_CHARTOITEM_REFLECT macro [MFC]
- ON_WM_CTLCOLOR_REFLECT macro [MFC]
- ON_WM_DELETEITEM_REFLECT macro [MFC]
- notification messages [MFC]
- ON_WM_PARENTNOTIFY_REFLECT macro [MFC]
- WM_NOTIFY message [MFC]
- ON_CONTROL_REFLECT macro
ms.assetid: 53efb0ba-fcda-4fa0-a3c7-14e0b78fb494
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: bdf9a0dd227cb54ba85c85901f706966326b1b66
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="tn062-message-reflection-for-windows-controls"></a>TN062: reflexão de mensagem para controles do Windows
> [!NOTE]
>  A Observação técnica a seguir não foi atualizada desde que ele foi incluído primeiro na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação on-line.  
  
 Essa observação técnica descreve reflexão de mensagem, um novo recurso no MFC 4.0. Ele também contém instruções para criar um controle reutilizável simples que usa reflexão de mensagem.  
  
 Essa observação técnica não aborda a reflexão de mensagem conforme ela se aplica aos controles ActiveX (anteriormente chamado de controles OLE). Consulte o artigo [controles ActiveX: subclasses de um controle de Windows](../mfc/mfc-activex-controls-subclassing-a-windows-control.md).  
  
 **O que é a reflexão de mensagem**  
  
 Controles de Windows frequentemente enviam mensagens de notificação para as janelas de pai. Por exemplo, muitos controles enviar uma mensagem de notificação do controle cor (`WM_CTLCOLOR` ou uma de suas variantes) para o pai, para permitir que o pai fornecer um pincel para pintar o plano de fundo do controle.  
  
 No Windows e no MFC antes da versão 4.0, a janela pai, geralmente uma caixa de diálogo é responsável por manipular essas mensagens. Isso significa que o código para manipular a mensagem precisa estar na classe da janela pai e que ele precisa ser duplicados em todas as classes necessárias para manipular a mensagem. Nesse caso, cada caixa de diálogo que desejava controles com planos de fundo personalizados precisa lidar com a mensagem de notificação do controle cor. Seria muito mais fácil reutilizar o código se uma classe de controle pode ser gravada que usaria sua própria cor de plano de fundo.  
  
 Em MFC 4.0, o mecanismo antigo ainda funciona — windows pai podem lidar com mensagens de notificação. Além disso, no entanto, 4.0 MFC facilita a reutilização, fornecendo um recurso chamado "reflexão de mensagem" que permite que essas mensagens de notificação deve ser tratado em janela de controle filho ou a janela pai, ou ambos. No exemplo a cor de plano de fundo controle, agora você pode escrever uma classe de controle que define sua própria cor de plano de fundo ao manipular o refletido `WM_CTLCOLOR` mensagem — tudo isso sem contar com o pai. (Observe que como reflexão de mensagem é implementada pelo MFC, não pelo Windows, a classe de janela pai deve ser derivada de `CWnd` para reflexão de mensagem trabalhar.)  
  
 Versões mais antigas do MFC faziam algo semelhante a reflexão de mensagem, fornecendo funções virtuais para algumas mensagens, como mensagens das caixas de listagem do desenho proprietário (`WM_DRAWITEM`, e assim por diante). O novo mecanismo de reflexão de mensagem é generalizada e consistente.  
  
 Reflexão de mensagem é compatível com o código escrito para versões do MFC antes de 4.0.  
  
 Se você tiver fornecido um manipulador para uma mensagem específica ou um intervalo de mensagens na classe da sua janela pai, ele substituirá refletidas manipuladores de mensagens para a mesma mensagem, desde que você não chama a função de manipulador de classe base em seu próprio manipulador. Por exemplo, se você tratar `WM_CTLCOLOR` na sua classe de caixa de diálogo, o tratamento substituirá qualquer manipuladores de mensagens refletidas.  
  
 Se, em sua classe de janela pai, você fornece um manipulador para um determinado **WM_NOTIFY** mensagem ou um intervalo de **WM_NOTIFY** mensagens, o manipulador será chamado apenas se o controle filho enviar as mensagens não tem um manipulador de mensagem refletida por meio de **ON_NOTIFY_REFLECT()**. Se você usar **ON_NOTIFY_REFLECT_EX()** em seu mapa de mensagem, o manipulador de mensagens pode ou não pode permitir que a janela pai manipular a mensagem. Se o manipulador retorna **FALSE**, a mensagem será tratada pelo pai, enquanto uma chamada que retorna **TRUE** não permite que o pai para tratá-la. Observe que a mensagem refletida é manipulada antes da mensagem de notificação.  
  
 Quando um **WM_NOTIFY** mensagem é enviada, o controle é oferecido a primeira chance de tratá-la. Se qualquer outra mensagem refletida for enviada, a janela pai tem a primeira oportunidade de tratá-la e o controle receberá a mensagem refletida. Para fazer isso, ele precisará de uma função de manipulador e uma entrada apropriada no mapa de mensagem de classe do controle.  
  
 A macro de mapa de mensagem para mensagens refletidas é ligeiramente diferente para notificações regulares: tem **_REFLECT** acrescentado ao nome comum. Por exemplo, para manipular um **WM_NOTIFY** mensagem no pai, você pode usar a macro `ON_NOTIFY` no mapa de mensagem do pai. Para manipular a mensagem refletida no controle filho, use o **ON_NOTIFY_REFLECT** macro no mapa de mensagem do controle filho. Em alguns casos, os parâmetros são diferentes, também. Observe que ClassWizard geralmente pode adicionar as entradas de mapa de mensagem para você e fornecer implementações de função em esqueleto com os parâmetros corretos.  
  
 Consulte [TN061: mensagens ON_NOTIFY e WM_NOTIFY](../mfc/tn061-on-notify-and-wm-notify-messages.md) para obter informações sobre o novo **WM_NOTIFY** mensagem.  
  
 **Entradas de mapa de mensagem e de protótipos de função do manipulador de mensagens refletidas**  
  
 Para lidar com uma mensagem de notificação do controle refletidas, use as macros de mapa de mensagem e protótipos de função listados na tabela a seguir.  
  
 ClassWizard geralmente pode adicionar essas entradas de mapa de mensagem para você e fornecer implementações de função em esqueleto. Consulte [definindo um manipulador de mensagens para uma mensagem refletida](../mfc/reference/defining-a-message-handler-for-a-reflected-message.md) para obter informações sobre como definir manipuladores de mensagens refletidas.  
  
 Para converter o nome da mensagem para o nome da macro refletidas, preceda **on _** e acrescente **_REFLECT**. Por exemplo, `WM_CTLCOLOR` se torna **ON_WM_CTLCOLOR_REFLECT**. (Para ver as mensagens que podem ser refletidas, fazer a conversão oposta nas entradas de macro na tabela abaixo).  
  
 As três exceções à regra acima são os seguintes:  
  
-   A macro **WM_COMMAND** notificações é **ON_CONTROL_REFLECT**.  
  
-   A macro **WM_NOTIFY** reflexos é **ON_NOTIFY_REFLECT**.  
  
-   A macro `ON_UPDATE_COMMAND_UI` reflexos é **ON_UPDATE_COMMAND_UI_REFLECT**.  
  
 Em cada um dos casos especiais acima, você deve especificar o nome da função do manipulador de membro. Em outros casos, você deve usar o nome padrão para a função do manipulador.  
  
 Os significados dos parâmetros e valores de retorno das funções estão documentados em nome da função ou o nome da função com **em** anexado. Por exemplo, **CtlColor** está documentado em `OnCtlColor`. Vários manipuladores de mensagem refletida necessário menos parâmetros que manipuladores semelhantes em uma janela pai. Apenas correspondem aos nomes na tabela a seguir com os nomes dos parâmetros formais na documentação.  
  
|Entrada de mapa|Protótipo da função|  
|---------------|------------------------|  
|**ON_CONTROL_REFLECT (** `wNotifyCode` **,** `memberFxn` **)**|**void afx_msg** `memberFxn` **();**|  
|**ON_NOTIFY_REFLECT (** `wNotifyCode` **,** `memberFxn` **)**|**void afx_msg** `memberFxn` **(NMHDR \***  `pNotifyStruct` **, LRESULT\***  *resultados* **);**|  
|**ON_UPDATE_COMMAND_UI_REFLECT (** `memberFxn` **)**|**void afx_msg** `memberFxn` **(CCmdUI\***  `pCmdUI` **);**|  
|**(ON_WM_CTLCOLOR_REFLECT)**|**afx_msg HBRUSH CtlColor (CDC\***  `pDC` **, UINT** `nCtlColor` **);**|  
|**(ON_WM_DRAWITEM_REFLECT)**|**afx_msg void DrawItem (LPDRAWITEMSTRUCT** `lpDrawItemStruct` **);**|  
|**(ON_WM_MEASUREITEM_REFLECT)**|**afx_msg void MeasureItem (LPMEASUREITEMSTRUCT** `lpMeasureItemStruct` **);**|  
|**(ON_WM_DELETEITEM_REFLECT)**|**afx_msg void DeleteItem (LPDELETEITEMSTRUCT** `lpDeleteItemStruct` **);**|  
|**(ON_WM_COMPAREITEM_REFLECT)**|**int afx_msg CompareItem (LPCOMPAREITEMSTRUCT** `lpCompareItemStruct` **);**|  
|**(ON_WM_CHARTOITEM_REFLECT)**|**int afx_msg CharToItem (UINT** `nKey` **, UINT** `nIndex` **);**|  
|**(ON_WM_VKEYTOITEM_REFLECT)**|**int afx_msg VKeyToItem (UINT** `nKey` **, UINT** `nIndex` **);**|  
|**(ON_WM_HSCROLL_REFLECT)**|**afx_msg void HScroll (UINT** `nSBCode` **, UINT** `nPos` **);**|  
|**(ON_WM_VSCROLL_REFLECT)**|**afx_msg void VScroll (UINT** `nSBCode` **, UINT** `nPos` **);**|  
|**(ON_WM_PARENTNOTIFY_REFLECT)**|**afx_msg void ParentNotify (UINT** `message` **, LPARAM** `lParam` **);**|  
  
 O **ON_NOTIFY_REFLECT** e **ON_CONTROL_REFLECT** macros tem variações que permitem que mais de um objeto (como o controle e seu pai) para lidar com uma determinada mensagem.  
  
|Entrada de mapa|Protótipo da função|  
|---------------|------------------------|  
|**ON_NOTIFY_REFLECT_EX (** `wNotifyCode` **,** `memberFxn` **)**|**afx_msg BOOL** `memberFxn` **(NMHDR \***  `pNotifyStruct` **, LRESULT\***  *resultados* **);**|  
|**ON_CONTROL_REFLECT_EX (** `wNotifyCode` **,** `memberFxn` **)**|**afx_msg BOOL** `memberFxn` **();**|  
  
## <a name="handling-reflected-messages-an-example-of-a-reusable-control"></a>Tratamento de mensagens de refletido: Um exemplo de um controle reutilizável  
 Este exemplo simple cria um controle reutilizável chamado `CYellowEdit`. O controle funciona da mesma forma um controle de edição regular, exceto que ele exibe o texto preto em um plano de fundo amarelo. Seria fácil adicionar funções de membro que permitem o `CYellowEdit` controle para exibir cores diferentes.  
  
#### <a name="to-try-the-example-that-creates-a-reusable-control"></a>Para testar o exemplo que cria um controle reutilizável  
  
1.  Crie uma nova caixa de diálogo em um aplicativo existente. Para obter mais informações, consulte o [editor de caixa de diálogo](../windows/dialog-editor.md) tópico.  
  
     Você deve ter um aplicativo no qual a desenvolver o controle reutilizável. Se você não tiver um aplicativo existente para usar, crie um aplicativo baseado na caixa de diálogo usando AppWizard.  
  
2.  Com o projeto carregado no Visual C++, use ClassWizard para criar uma nova classe chamada `CYellowEdit` com base em `CEdit`.  
  
3.  Adicionar três variáveis de membro para o `CYellowEdit` classe. Os dois primeiros serão **COLORREF** variáveis para manter a cor do texto e a cor do plano de fundo. A terceira será um `CBrush` objeto que conterá o pincel para pintar o plano de fundo. O `CBrush` objeto permite que você criar o pincel de uma vez, simplesmente fazem referência a ele depois que e destruir o pincel automaticamente quando o `CYellowEdit` controle é destruído.  
  
4.  Inicialize as variáveis de membro, escrevendo o construtor da seguinte maneira:  
  
 ```  
    CYellowEdit::CYellowEdit() 
 {  
    m_clrText = RGB(0,
    0,
    0);

    m_clrBkgnd = RGB(255,
    255,
    0);

    m_brBkgnd.CreateSolidBrush(m_clrBkgnd);

 }  
 ```  
  
5.  Usando ClassWizard, adicione um manipulador para o refletido `WM_CTLCOLOR` mensagem para sua `CYellowEdit` classe. Observe que o sinal de igual na frente do nome de mensagem na lista de mensagens, que você pode manipular indica que a mensagem seja refletida. Isso é descrito em [definindo um manipulador de mensagens para uma mensagem refletida](../mfc/reference/defining-a-message-handler-for-a-reflected-message.md).  
  
     ClassWizard adiciona a seguinte função de macro e esqueleto de mapa de mensagem para você:  
  
 ```  
    ON_WM_CTLCOLOR_REFLECT() 
 *// Note: other code will be in between....  
 
    HBRUSH CYellowEdit::CtlColor(CDC* pDC, UINT nCtlColor)   
 { *// TODO: Change any attributes of the DC here  
 *// TODO: Return a non-NULL brush if the *//   parent's handler should not be called  
    return NULL;  
 }  
 ```  
  
6.  Substitua o corpo da função com o código a seguir. O código especifica a cor do texto, a cor de plano de fundo do texto e a cor de plano de fundo para o restante do controle.  
  
 ```  
    pDC->SetTextColor(m_clrText);
*// text  
    pDC->SetBkColor(m_clrBkgnd);
*// text bkgnd  
    return m_brBkgnd;            // ctl bkgnd  
 ```  
  
7.  Criar um controle de edição na caixa de diálogo, em seguida, anexá-lo a uma variável de membro clicando duas vezes o controle de edição, enquanto pressiona uma tecla de controle. Na caixa de diálogo Adicionar variável de membro, conclua o nome da variável e escolha "Control" para a categoria, em seguida, "CYellowEdit" para o tipo de variável. Não se esqueça de definir a ordem das guias na caixa de diálogo. Além disso, certifique-se de incluir o arquivo de cabeçalho para o `CYellowEdit` controle no arquivo de cabeçalho da caixa de diálogo.  
  
8.  Compilar e executar seu aplicativo. O controle de edição terá um plano de fundo amarelo.  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

