---
title: "Editar estilos | Microsoft Docs"
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
  - "ES_READONLY"
  - "ES_WANTRETURN"
  - "ES_UPPERCASE"
  - "ES_NUMBER"
  - "ES_AUTOHSCROLL"
  - "ES_LOWERCASE"
  - "ES_RIGHT"
  - "ES_MULTILINE"
  - "ES_PASSWORD"
  - "ES_NOHIDESEL"
  - "ES_OEMCONVERT"
  - "ES_LEFT"
  - "ES_CENTER"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "estilos de edição [MFC]"
  - "Constante ES_AUTOHSCROLL"
  - "Constante ES_AUTOVSCROLL"
  - "Constante ES_CENTER"
  - "Constante ES_LEFT"
  - "Constante ES_LOWERCASE"
  - "Constante ES_MULTILINE"
  - "Constante ES_NOHIDESEL"
  - "Constante ES_NUMBER"
  - "Constante ES_OEMCONVERT"
  - "Constante ES_PASSWORD"
  - "Constante ES_READONLY"
  - "Constante ES_RIGHT"
  - "Constante ES_UPPERCASE"
  - "Constante ES_WANTRETURN"
ms.assetid: e6291dd6-f2cb-4ce2-ac31-32272526625c
caps.latest.revision: 12
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Editar estilos
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

-   **ES\_AUTOHSCROLL** rolar automaticamente o texto à direita em 10 caracteres quando o usuário um caractere no final da linha.  Quando o usuário pressionar a tecla ENTER, o controle coloque todo o texto de volta para a posição 0.  
  
-   **ES\_AUTOVSCROLL** rolar automaticamente o texto acima de uma página quando o usuário pressionar ENTER na última linha.  
  
-   **ES\_CENTER** centraliza o texto em um controle de edição de uma linha ou multilinha.  
  
-   **ES\_LEFT** sem\-recuo alinhe o texto em um controle de edição de uma linha ou multilinha.  
  
-   **ES\_LOWERCASE** converte todos os caracteres em minúsculas como são digitados em controle de edição.  
  
-   **ES\_MULTILINE** designa um controle de edição de várias linhas. \(O padrão é única linha.\) Se o estilo de **ES\_AUTOVSCROLL** for especificado, o controle de edição mostra tantas linhas quanto possível e confirmadas verticalmente quando o usuário pressionar a tecla ENTER.  Se **ES\_AUTOVSCROLL** não for fornecido, o controle de edição mostra tantas linhas quanto possível e sinais acústicos se ENTER é pressionada quando não há mais linhas pode ser exibida.  Se o estilo de **ES\_AUTOHSCROLL** for especificado, o controle de edição de várias linhas percorrer horizontalmente automaticamente quando o ponto de intercalação ultrapassará a borda direita do controle.  Para iniciar uma nova linha, o usuário deve pressionar ENTER.  Se **ES\_AUTOHSCROLL** não for fornecido, o controle envolve automaticamente palavras para o início da linha seguinte quando necessário; uma nova linha é iniciada também se ENTER é pressionada.  A posição da quebra automática de linha é determinada pelo tamanho da janela.  Se o tamanho da janela for alterada, a posição da quebra automática de linha alterações e o texto redisplayed.  Os controles de edição de várias linhas podem ter barras de rolagem.  Um controle de edição com barras de rolagem processa suas próprias mensagens da barra de rolagem.  Os controles de edição sem barras de rolagem vá como descrito acima e processa todas as mensagens de rolagem enviadas pela janela pai.  
  
-   **ES\_NOHIDESEL** normalmente, um controle de edição oculta a seleção quando o controle perde o foco de entrada e inverte a seleção quando o controle recebe o foco de entrada.  Especificando **ES\_NOHIDESEL** excluir essa ação padrão.  
  
-   **ES\_NUMBER** permite que somente os dígitos são inseridos no controle de edição.  
  
-   O texto de**ES\_OEMCONVERT**inserida no controle de edição é convertido do conjunto de caracteres ANSI ao conjunto de caracteres OEM e volta para a ANSI.  Isso assegura a conversão de caracteres apropriada quando o aplicativo chama a função do windows de `AnsiToOem` para converter uma cadeia de caracteres ANSI no controle de edição os caracteres OEM.  Esse estilo é muito útil para os controles de edição que contêm nomes de arquivo.  
  
-   **ES\_PASSWORD** exibe todos os caracteres como um asterisco \(\) como**\***são digitados em controle de edição.  Um aplicativo pode usar a função de membro de `SetPasswordChar` para alterar o caractere que é exibido.  
  
-   **ES\_READONLY** impede que o usuário insira ou editar o texto no controle de edição.  
  
-   **ES\_RIGHT** ele alinhe o texto em um controle de edição de uma linha ou multilinha.  
  
-   **ES\_UPPERCASE** converte todos os caracteres em maiúsculas como são digitados em controle de edição.  
  
-   **ES\_WANTRETURN** especifica que um retorno de carro seja inserido quando o usuário pressionar a tecla ENTER ao inserir o texto em um controle de edição de várias linhas em uma caixa de diálogo.  Sem esse estilo, pressione a tecla ENTER tem o mesmo efeito que pressionando a tecla padrão das caixas de diálogo.  Esse estilo não tem nenhum efeito em um controle de edição de linha única.  
  
## Consulte também  
 [Estilos usados pelo MFC](../../mfc/reference/styles-used-by-mfc.md)   
 [CEdit::Create](../Topic/CEdit::Create.md)   
 [Edit Control Styles](http://msdn.microsoft.com/library/windows/desktop/bb775464)