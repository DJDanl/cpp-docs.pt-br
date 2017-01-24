---
title: "TN062: reflex&#227;o de mensagem para controles do Windows | Microsoft Docs"
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
  - "vc.controls.messages"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "reflexão de mensagem"
  - "mensagens de notificação"
  - "Macro ON_CONTROL_REFLECT"
  - "Macro ON_CONTROL_REFLECT_EX"
  - "ON_NOTIFY (mensagem)"
  - "ON_NOTIFY_REFLECT (mensagem)"
  - "ON_NOTIFY_REFLECT_EX (mensagem)"
  - "Macro ON_UPDATE_COMMAND_UI_REFLECT"
  - "Macro ON_WM_CHARTOITEM_REFLECT"
  - "Macro ON_WM_COMPAREITEM_REFLECT"
  - "Macro ON_WM_CTLCOLOR_REFLECT"
  - "Macro ON_WM_DELETEITEM_REFLECT"
  - "Macro ON_WM_DRAWITEM_REFLECT"
  - "Macro ON_WM_HSCROLL_REFLECT"
  - "Macro ON_WM_MEASUREITEM_REFLECT"
  - "Macro ON_WM_PARENTNOTIFY_REFLECT"
  - "Macro ON_WM_VKEYTOITEM_REFLECT"
  - "Macro ON_WM_VSCROLL_REFLECT"
  - "TN062"
  - "WM_COMMAND"
  - "WM_CTLCOLOR (mensagem)"
  - "WM_NOTIFY (mensagem)"
ms.assetid: 53efb0ba-fcda-4fa0-a3c7-14e0b78fb494
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN062: reflex&#227;o de mensagem para controles do Windows
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que ela foi incluída pela primeira vez na documentação online.  Como resultado, alguns procedimentos e tópicos podem estar incorretos ou expirados.  Para obter as informações mais recentes, é recomendável que você procure o tópico de interesse no índice de documentação online.  
  
 Observe que essa técnica descreve a reflexão de mensagem, um novo recurso em MFC 4,0.  Também contém instruções para criar um controle reutilizável simples que usa a reflexão de mensagem.  
  
 Observe que essa técnica não discute a reflexão de mensagem como se aplica aos controles ActiveX \(chamado anteriormente controladores OLE\).  Consulte o artigo [Controles ActiveX: Subclassing controla o windows](../mfc/mfc-activex-controls-subclassing-a-windows-control.md).  
  
 **Que é reflexão de mensagem?**  
  
 Os controles do windows geralmente envia notificações para as janelas pai.  Por exemplo, muitos controles envia uma notificação de cor de controle \(`WM_CTLCOLOR` ou uma de suas variantes\) com o pai para permitir que o pai fornece uma escova para pintar o plano de fundo do controle.  
  
 No windows e no MFC antes da versão 4,0, a janela pai, geralmente uma caixa de diálogo, é responsável para tratar essas mensagens.  Isso significa que o código de manipulação que a mensagem precisa estar na classe pai da janela e que tem que ser duplicadas em cada classe que precisa tratar essa mensagem.  No caso acima, cada caixa de diálogo que controla desejados com planos de fundo personalizados devem lidar com que a notificação de cor do controle.  Seria muito mais fácil reutilizar o código se uma classe do controle pode ser gravada que trata sua própria cor do plano de fundo.  
  
 Em MFC 4,0, o mecanismo antigo ainda funciona — o pai podem tratar notificações.  Além disso, o entanto, o MFC 4,0 facilita reutilização fornecendo um recurso chamado de “reflexão a mensagem” que permite que as notificações são tratadas na janela de controle filho ou na janela pai, ou em ambos.  No exemplo da cor de plano de fundo de controle, agora você pode gravar uma classe de controle que define sua própria cor do plano de fundo executando a mensagem refletida de `WM_CTLCOLOR` — tudo sem depender no pai. \(Observe que desde que a reflexão de mensagem é implementada por MFC, não pelo windows, a classe pai da janela deve ser derivada de `CWnd` para que a reflexão de mensagem funcione.\)  
  
 As versões anteriores de MFC fazer algo semelhante à reflexão de mensagem fornecendo funções virtuais para algumas mensagens, como mensagens para caixas de listagem proprietário\- desenhadas \(`WM_DRAWITEM`, e assim por diante\).  O novo mecanismo de reflexão de mensagem é generalizado e consistente.  
  
 A reflexão de mensagem é inversa compatível com o código escrito para versões de MFC antes de 4,0.  
  
 Se você forneceu um manipulador de uma mensagem específica, ou para um intervalo de mensagens, na classe pai da janela, substituirá refletido manipuladores de mensagem para a mesma mensagem caso não chama a função de manipulador da classe base em seu próprio manipulador.  Por exemplo, se você trata `WM_CTLCOLOR` em sua classe da caixa de diálogo, a manipulação substituirá todos os manipuladores de mensagem refletidas.  
  
 Se, em sua classe pai da janela, você fornece um manipulador de uma mensagem específica de **WM\_NOTIFY** ou um intervalo de mensagens de **WM\_NOTIFY** , o manipulador será chamado somente se o controle filho que envia as mensagens não tem um manipulador de mensagens refletido com **ON\_NOTIFY\_REFLECT\(\)**.  Se você usar **ON\_NOTIFY\_REFLECT\_EX\(\)** em seu mapa da mensagem, o manipulador de mensagens pode ou não pode permitir que a janela pai controle a mensagem.  Se o manipulador retorna **Falso**, a mensagem será tratada pelo pai além disso, quando uma chamada que retorna **Verdadeiro** não permitir que o pai o controle.  Observe que a mensagem refletida será tratada antes de notificação.  
  
 Quando uma mensagem de **WM\_NOTIFY** é enviada, o controle é oferecido a primeira oportunidade tratá\-la.  Se qualquer outra mensagem refletida é enviada, a janela pai tem a possibilidade primeira tratá\-la e o controle receberá a mensagem refletida.  Para fazer isso, precisará de uma função de manipulador e uma entrada apropriada da mensagem da classe do controle.  
  
 A macro retornadas mapa para mensagens refletidas é um pouco diferente do que para notificações comuns: tem **\_REFLECT** anexado ao nome comum.  Por exemplo, para tratar uma mensagem de **WM\_NOTIFY** o pai, você usa `ON_NOTIFY` macro da mensagem do pai.  Para controlar a mensagem refletida no controle filho, use a macro de **ON\_NOTIFY\_REFLECT** no mapa filho da mensagem do controle.  Em alguns casos, os parâmetros são diferentes, também.  Observe que ClassWizard geralmente pode adicionar as entradas retornadas mapa para você e fornecer implementações de esqueleto de função com parâmetros corretos.  
  
 Consulte [TN061: Mensagens de ON\_NOTIFY e de WM\_NOTIFY](../mfc/tn061-on-notify-and-wm-notify-messages.md) para obter informações sobre a nova mensagem de **WM\_NOTIFY** .  
  
 **Entradas retornadas mapa e protótipos de função de manipulador de mensagens refletidas**  
  
 Para tratar uma notificação refletida de controle, para usar macros retornadas o mapa e os protótipos de função listados na tabela abaixo.  
  
 ClassWizard geralmente pode adicionar essas entradas retornadas mapa para você e fornecer implementações de esqueleto da função.  Consulte [Definindo um manipulador de mensagem para uma mensagem refletida](../mfc/reference/defining-a-message-handler-for-a-reflected-message.md) para obter informações sobre como definir manipuladores para mensagens refletidas.  
  
 Para converter o nome da mensagem ao nome da macro refletido, precede **ON\_** e anexar **\_REFLECT**.  Por exemplo, `WM_CTLCOLOR` se torna **ON\_WM\_CTLCOLOR\_REFLECT**. \(Para ver quais mensagens podem ser refletidas, faça a conversão oposta macro nas entradas na tabela abaixo\).  
  
 As três exceções à regra anterior são os seguintes:  
  
-   A macro para notificações de **WM\_COMMAND** é **ON\_CONTROL\_REFLECT**.  
  
-   A macro para reflexões de **WM\_NOTIFY** é **ON\_NOTIFY\_REFLECT**.  
  
-   A macro para reflexões de `ON_UPDATE_COMMAND_UI` é **ON\_UPDATE\_COMMAND\_UI\_REFLECT**.  
  
 Em cada um dos casos especiais anteriores, você deve especificar o nome da função de membro do manipulador.  Em outros casos, você deve usar o nome padrão da função de manipulador.  
  
 Os significados dos parâmetros e valores de retorno de funções são documentados em ou nome de função ou nome de função com **On** é pré\-anexado.  Por exemplo, **CtlColor** é documentado em `OnCtlColor`.  Vários manipuladores de mensagem refletidas precisam menos parâmetros dos manipuladores semelhantes em uma janela pai.  A correspondência apenas os nomes na tabela abaixo com os nomes dos parâmetros formais na documentação do.  
  
|Entrada do mapa|Protótipo de função|  
|---------------------|-------------------------|  
|**ON\_CONTROL\_REFLECT\(**  `wNotifyCode` **,**  `memberFxn`  **\)**|**afx\_msg void**  `memberFxn`  **\( \);**|  
|**ON\_NOTIFY\_REFLECT\(**  `wNotifyCode` **,**  `memberFxn`  **\)**|*resultado*\);de**afx\_msg void** `memberFxn` **\( NMHDR \*** `pNotifyStruct`**, LRESULT\***|  
|**ON\_UPDATE\_COMMAND\_UI\_REFLECT\(**  `memberFxn`  **\)**|**afx\_msg void**  `memberFxn`  **\( CCmdUI\***  `pCmdUI`\);|  
|**ON\_WM\_CTLCOLOR\_REFLECT \(\)**|**afx\_msg HBRUSH CtlColor \( CDC\***  `pDC` **, UINT**  `nCtlColor`\);|  
|**ON\_WM\_DRAWITEM\_REFLECT \(\)**|**afx\_msg void DrawItem \( LPDRAWITEMSTRUCT**  `lpDrawItemStruct`\);|  
|**ON\_WM\_MEASUREITEM\_REFLECT \(\)**|**afx\_msg void MeasureItem \( LPMEASUREITEMSTRUCT**  `lpMeasureItemStruct`\);|  
|**ON\_WM\_DELETEITEM\_REFLECT \(\)**|**afx\_msg void DeleteItem \( LPDELETEITEMSTRUCT**  `lpDeleteItemStruct`\);|  
|**ON\_WM\_COMPAREITEM\_REFLECT \(\)**|**afx\_msg int CompareItem \( LPCOMPAREITEMSTRUCT**  `lpCompareItemStruct`\);|  
|**ON\_WM\_CHARTOITEM\_REFLECT \(\)**|**afx\_msg int CharToItem \( UINT**  `nKey` **, UINT**  `nIndex`\);|  
|**ON\_WM\_VKEYTOITEM\_REFLECT \(\)**|**afx\_msg int VKeyToItem \( UINT**  `nKey` **, UINT**  `nIndex`\);|  
|**ON\_WM\_HSCROLL\_REFLECT \(\)**|**afx\_msg void HScroll \( UINT**  `nSBCode` **, UINT**  `nPos`\);|  
|**ON\_WM\_VSCROLL\_REFLECT \(\)**|**afx\_msg void VScroll \( UINT**  `nSBCode` **, UINT**  `nPos`\);|  
|**ON\_WM\_PARENTNOTIFY\_REFLECT \(\)**|**afx\_msg void ParentNotify \( UINT**  `message` **, LPARAM**  `lParam`\);|  
  
 Macros de **ON\_NOTIFY\_REFLECT** e de **ON\_CONTROL\_REFLECT** têm as variações que permite que mais de um objeto \(como o controle e seu pai\) lidar com uma mensagem fornecida.  
  
|Entrada do mapa|Protótipo de função|  
|---------------------|-------------------------|  
|**ON\_NOTIFY\_REFLECT\_EX\(**  `wNotifyCode` **,**  `memberFxn`  **\)**|*resultado*\);de**afx\_msg BOOL** `memberFxn` **\( NMHDR \*** `pNotifyStruct`**, LRESULT\***|  
|**ON\_CONTROL\_REFLECT\_EX\(**  `wNotifyCode` **,**  `memberFxn`  **\)**|**afx\_msg BOOL**  `memberFxn`  **\( \);**|  
  
## Tratando mensagens refletidas: Um exemplo de um controle reutilizável  
 Esse exemplo simples cria um controle reutilizável chamado `CYellowEdit`.  O controle funciona da mesma forma que um controle de edição normal exceto que exibe o texto preto em um plano de fundo amarelo.  Seria fácil adicionar as funções de membro que permitiriam que o controle de `CYellowEdit` exibe cores diferentes.  
  
#### Para testar o exemplo que cria um controle reutilizável  
  
1.  Crie uma nova caixa de diálogo em um aplicativo existente.  Para obter mais informações, consulte o tópico de [editor da caixa de diálogo](../mfc/dialog-editor.md) .  
  
     Você deve ter um aplicativo no qual o para desenvolver o controle reutilizável.  Se você não tiver um aplicativo existente para usar o, crie um aplicativo baseado diálogo\- usando AppWizard.  
  
2.  Com o projeto carregado no Visual C\+\+, use ClassWizard para criar uma nova classe chamada `CYellowEdit` baseado em `CEdit`.  
  
3.  Adicionar variáveis de três membros à sua classe de `CYellowEdit` .  Os dois primeiros serão variáveis de **COLORREF** para manter a cor de texto e cor de fundo.  O terceiro será um objeto de `CBrush` que contém a escova para pintar o plano de fundo.  O objeto de `CBrush` permite que você crie a escova uma vez, simplesmente referenciando a após o, e destruir a escova automaticamente quando o controle de `CYellowEdit` é destruído.  
  
4.  Inicializar as variáveis de membro gravando o construtor da seguinte maneira:  
  
    ```  
    CYellowEdit::CYellowEdit()  
    {  
       m_clrText = RGB( 0, 0, 0 );  
       m_clrBkgnd = RGB( 255, 255, 0 );  
       m_brBkgnd.CreateSolidBrush( m_clrBkgnd );  
    }  
    ```  
  
5.  Usando ClassWizard, adicionar um manipulador para a mensagem refletida de `WM_CTLCOLOR` a sua classe de `CYellowEdit` .  Observe que o sinal de igualdade em frente do nome da mensagem na lista de mensagens que você pode controlar indica que a mensagem será refletida.  Isso é descrito em [Definindo um manipulador de mensagem para uma mensagem refletida](../mfc/reference/defining-a-message-handler-for-a-reflected-message.md).  
  
     ClassWizard adiciona o seguinte macro retornadas mapa e a função do esqueleto do:  
  
    ```  
    ON_WM_CTLCOLOR_REFLECT()  
  
    // Note: other code will be in between....  
  
    HBRUSH CYellowEdit::CtlColor(CDC* pDC, UINT nCtlColor)   
    {  
       // TODO: Change any attributes of the DC here  
  
       // TODO: Return a non-NULL brush if the  
       //   parent's handler should not be called  
       return NULL;  
    }  
    ```  
  
6.  Substitua o corpo da função com o código a seguir.  O código especifica a cor do texto, a cor do plano de fundo de texto, e a cor do plano de fundo para o restante do controle.  
  
    ```  
    pDC->SetTextColor( m_clrText );   // text  
    pDC->SetBkColor( m_clrBkgnd );   // text bkgnd  
    return m_brBkgnd;            // ctl bkgnd  
    ```  
  
7.  Crie um controle de edição na caixa de diálogo, então anexá\-lo a uma variável de membro clicando duas vezes no controle de edição mantendo uma chave de controle.  Na caixa de diálogo variável de membro, adicionar concluir o nome da variável e escolha o controle “” para a categoria, então “CYellowEdit” para o tipo de variável.  Não esqueça definir a ordem da guia na caixa de diálogo.  Além disso, inclua o arquivo de cabeçalho do controle de `CYellowEdit` em seu arquivo de cabeçalho na caixa de diálogo.  
  
8.  Compile e execute seu aplicativo.  O controle de edição terá um plano de fundo amarelo.  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)