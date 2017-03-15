---
title: "Manipuladores para mensagens do Windows padr&#227;o | Microsoft Docs"
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
  - "afx_msg"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "funções [C++], manipulador"
  - "funções de manipulador, mensagens padrão do Windows"
  - "tratamento de mensagens [C++], manipuladores de mensagens do Windows"
  - "mensagens [C++], Janelas"
  - "mensagens do Windows [C++], manipuladores"
ms.assetid: 19412a8b-2c38-4502-81da-13c823c7e36c
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Manipuladores para mensagens do Windows padr&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os manipuladores padrão para mensagens padrão do windows \(**WM\_**\) são predefinidos na classe `CWnd`.  A biblioteca de classes utilizar nomes desses manipuladores do nome da mensagem.  Por exemplo, o manipulador para a mensagem de `WM_PAINT` for declarado em `CWnd` como:  
  
 `afx_msg void OnPaint();`  
  
 A palavra\-chave de **afx\_msg** sugere o efeito da palavra\-chave C\+\+ **virtual** distinguindo os manipuladores de outras funções de membro de `CWnd` .  Observe, no entanto, essas funções que não são de fato virtuais; são implementados em vez de pelos mapas da mensagem.  Os mapas de mensagem somente dependem de macros padrão de pré\-processador, não de todas as extensões da linguagem C\+\+.  A palavra\-chave de **afx\_msg** resolve para o espaço em branco depois de pré\-processamento.  
  
 Para substituir um manipulador definido em uma classe base, defina apenas uma função com o mesmo protótipo em sua classe derivada e criar uma entrada retornadas o mapa do manipulador.  O manipulador “” substitui qualquer manipulador de mesmo nome em qualquer uma das classes base da classe.  
  
 Em alguns casos, o manipulador deve chamar o manipulador substituído em uma classe base para que a classe base e o windows podem operar na mensagem.  Quando você chama o manipulador da classe base em sua substituição depende das condições.  Às vezes você deve chamar o manipulador da classe base primeiro e às vezes durá\-lo.  Às vezes você chama o manipulador da classe base condicional, se você escolher não tratar a mensagem você mesmo.  Às vezes você deve chamar o manipulador da classe base, então condicional para executar seu próprio código do manipulador, dependendo do valor ou o estado retornada pelo manipulador da classe base.  
  
> [!CAUTION]
>  Não é seguro alterar os argumentos passados em um manipulador se você pretende os passados para um manipulador da classe base.  Por exemplo, você poderia ser tentado alterar o argumento de `nChar` do manipulador de `OnChar` \(para converter para letras maiúsculas, por exemplo\).  Esse comportamento é razoavelmente obscuro, mas se você precisa realizar esse efeito, use a função de membro **SendMessage** de `CWnd` em vez disso.  
  
 Como você determina o modo adequado de substituir uma mensagem fornecida?  Quando a janela Propriedades grava o esqueleto da função de manipulador para uma determinada mensagem — um manipulador de `OnCreate` para `WM_CREATE`, por exemplo destaca — na forma da função de membro substituída recomendada.  O exemplo a seguir recomenda que a chamada do manipulador primeiro o manipulador da classe base e continua somente contanto que não retorna – 1.  
  
 [!CODE [NVC_MFCMessageHandling#3](../CodeSnippet/VS_Snippets_Cpp/NVC_MFCMessageHandling#3)]  
  
 Por convenção, os nomes desses manipuladores começam com o prefixo “em.” Alguns desses manipuladores não têm nenhum argumento, enquanto outros precisam de muitos.  Alguns também têm um tipo de retorno diferente `void`.  Os manipuladores padrão para todas as mensagens de **WM\_** são documentados na *referência de MFC* como funções de membro da classe `CWnd` cujos nomes começam com “em.” As declarações de função de membro em `CWnd` são prefixadas com **afx\_msg**.  
  
## Consulte também  
 [Declarando funções de manipulador de mensagens](../mfc/declaring-message-handler-functions.md)