---
title: Editar estilos | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ES_READONLY
- ES_WANTRETURN
- ES_UPPERCASE
- ES_NUMBER
- ES_AUTOHSCROLL
- ES_LOWERCASE
- ES_RIGHT
- ES_MULTILINE
- ES_PASSWORD
- ES_NOHIDESEL
- ES_OEMCONVERT
- ES_LEFT
- ES_CENTER
dev_langs:
- C++
helpviewer_keywords:
- ES_WANTRETURN constant
- edit styles [MFC]
- ES_RIGHT constant
- ES_READONLY constant
- ES_PASSWORD constant
- ES_MULTILINE constant
- ES_LEFT constant
- ES_AUTOVSCROLL constant
- ES_OEMCONVERT constant
- ES_LOWERCASE constant
- ES_NUMBER constant
- ES_UPPERCASE constant
- ES_NOHIDESEL constant
- ES_AUTOHSCROLL constant
- ES_CENTER constant
ms.assetid: e6291dd6-f2cb-4ce2-ac31-32272526625c
caps.latest.revision: 12
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 275e0d2dede038bdbe9061bc8051408442aa70bf
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="edit-styles"></a>Editar estilos
-   **ES_AUTOHSCROLL** rola automaticamente o texto à direita por 10 caracteres quando o usuário digita um caractere no final da linha. Quando o usuário pressiona a tecla ENTER, o controle rola todo o texto para a posição 0.  
  
-   **ES_AUTOVSCROLL** rola automaticamente o texto para cima uma página quando o usuário pressiona ENTER na última linha.  
  
-   **ES_CENTER** controle de edição de texto Centers em uma linha única ou multilinha.  
  
-   **ES_LEFT** controle de edição de texto alinha à esquerda em uma linha única ou multilinha.  
  
-   **ES_LOWERCASE** converte todos os caracteres para letras minúsculas quando eles são digitados no controle de edição.  
  
-   **ES_MULTILINE** designa um controle de edição de várias linhas. (O padrão é a única linha.) Se o **ES_AUTOVSCROLL** estilo for especificado, o controle de edição mostra tantas linhas quanto possível e rola verticalmente quando o usuário pressiona a tecla ENTER. Se **ES_AUTOVSCROLL** não é fornecido, o controle de edição mostra tantas linhas quanto possível e sinais sonoros se ENTER é pressionada quando não há mais linhas podem ser exibidas. Se o **ES_AUTOHSCROLL** estilo for especificado, o controle de edição de várias linhas automaticamente rola horizontalmente quando o cursor vai além da borda direita do controle. Para iniciar uma nova linha, o usuário deverá pressionar ENTER. Se **ES_AUTOHSCROLL** não é fornecido, o controle automaticamente quebra de palavras para o início da próxima linha quando necessário; uma nova linha é iniciada se ENTER é pressionada. A posição do wordwrap é determinada pelo tamanho da janela. Se o tamanho da janela for alterado, as alterações na posição wordwrap e o texto é exibida novamente. Controles de edição de várias linhas podem ter barras de rolagem. Um controle de edição com barras de rolagem processa suas próprias mensagens da barra de rolagem. Editar controles sem rolagem barras de rolagem conforme descrito acima e processar as mensagens de rolagem enviadas pela janela pai.  
  
-   **ES_NOHIDESEL** normalmente, um controle de edição oculta a seleção quando o controle perde o foco de entrada e inverte a seleção quando o controle recebe o foco de entrada. Especificando **ES_NOHIDESEL** exclui essa ação padrão.  
  
-   **ES_NUMBER** permite que somente os dígitos a serem inseridas no controle de edição.  
  
-   **ES_OEMCONVERT** texto inserido no controle de edição é convertido do conjunto de caracteres ANSI para o conjunto de caracteres OEM e depois como ANSI. Isso garante a conversão de caracteres adequada quando o aplicativo chama o `AnsiToOem` função do Windows para converter uma cadeia de caracteres ANSI no controle de edição para caracteres OEM. Esse estilo é mais útil para controles de edição que contêm nomes de arquivos.  
  
-   **ES_PASSWORD** exibe todos os caracteres como um asterisco (**\***) quando eles são digitados no controle de edição. Um aplicativo pode usar o `SetPasswordChar` a função de membro para alterar o caractere que é exibido.  
  
-   **ES_READONLY** impede que o usuário inserir ou editar o texto no controle de edição.  
  
-   **ES_RIGHT** controle de edição de texto à direita em uma linha única ou multilinha.  
  
-   **ES_UPPERCASE** converte todos os caracteres para letras maiusculas quando eles são digitados no controle de edição.  
  
-   **ES_WANTRETURN** Especifica que um retorno de carro inserido quando o usuário pressiona a tecla ENTER ao inserir texto em um controle de edição de várias linhas em uma caixa de diálogo. Sem esse estilo, pressionando a tecla ENTER tem o mesmo efeito que pressionar o botão de ação de padrão de caixas de diálogo. Este estilo não tem nenhum efeito em uma única linha controle de edição.  
  
## <a name="see-also"></a>Consulte também  
 [Estilos usados pelo MFC](../../mfc/reference/styles-used-by-mfc.md)   
 [CEdit::Create](../../mfc/reference/cedit-class.md#create)   
 [Editar estilos de controle](http://msdn.microsoft.com/library/windows/desktop/bb775464)


