---
title: "/volatile (Interpreta&#231;&#227;o da palavra-chave volatile) | Microsoft Docs"
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
  - "/volatile:iso"
  - "/volatile:ms"
  - "/volatile"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção /volatile do compilador"
  - "Opção /volatile do compilador [C++]"
  - "Opção volatile do compilador"
  - "Opção -volatile do compilador"
  - "Opção volatile do compilador [C++]"
  - "Opção -volatile do compilador [C++]"
ms.assetid: 9d08fcc6-5bda-44c8-8151-8d8d54f164b8
caps.latest.revision: 15
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /volatile (Interpreta&#231;&#227;o da palavra-chave volatile)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica como a palavra\-chave [volatile](../../cpp/volatile-cpp.md) deve ser interpretada.  
  
## Sintaxe  
  
```  
/volatile:{iso|ms}  
```  
  
## Arguments  
 **\/volatile:iso**  
 Seleciona a semântica estrita de `volatile` conforme definido pela linguagem ISO C\+\+ padrão.  A semântica de aquisição\/liberação não é garantida em acessos voláteis.  Se o compilador direciona o ARM, essa é a interpretação padrão do `volatile`.  
  
 **\/volatile:ms**  
 Seleciona a semântica estendida de `volatile` da Microsoft, o que adiciona garantias de solicitação de de memória além da linguagem C\+\+ padrão ISO.  A semântica de aquisição\/liberação é garantida em acessos voláteis.  No entanto, essa opção também força o compilador a gerar as barreiras de memória de hardware, que podem adicionar uma sobrecarga significativa ao BRAÇO e a outras arquiteturas fracas de classificação de memória.  Se o compilador direciona qualquer plataforma exceto o ARM, essa é uma interpretação padrão do `volatile`.  
  
## Comentários  
 É altamente recomendável que você use **\/volatile:iso** junto com primitivos explícitos de sincronização e os intrínsecos de compilador quando estiver tratando a memória que é compartilhado entre threads.  Para obter mais informações, consulte [volatile](../../cpp/volatile-cpp.md).  
  
 Se você portar o código existente ou alterar essa opção no meio de um projeto, poderá ser útil habilitar o aviso [C4746](../../error-messages/compiler-warnings/compiler-warning-c4746.md) para identificar locais de código afetados pela diferença na semântica.  
  
 Não há equivalente de `#pragma` para controlar esta opção.  
  
### Para definir a opção \/volatile do compilador no Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** para o projeto.  Para obter mais informações, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Selecione a pasta **C\/C\+\+**.  
  
3.  Selecione a página de propriedades **Linha de Comando** .  
  
4.  Na caixa **Opções adicionais**, adicione `/volatile:iso` ou `/volatile:ms`.  
  
## Consulte também  
 [volatile](../../cpp/volatile-cpp.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)