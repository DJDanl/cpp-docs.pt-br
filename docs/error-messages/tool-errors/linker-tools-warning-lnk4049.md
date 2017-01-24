---
title: "Aviso LNK4049 (Ferramentas de Vinculador) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "LNK4049"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK4049"
ms.assetid: 5fd5fb24-c860-4149-a557-0ac26a65d97c
caps.latest.revision: 19
caps.handback.revision: 19
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso LNK4049 (Ferramentas de Vinculador)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

símbolo localmente definida “símbolo” importado  
  
 O símbolo foi exportado de e importado para o programa.  
  
 Esse aviso é gerado pelo vinculador quando declara um símbolo usando o atributo de armazenamento classe de `__declspec(dllexport)` em um arquivo do objeto e o faz referência usando o atributo de `__declspec(dllimport)` em outro.  
  
 LNK4049 de aviso é uma versão mais geral de [Aviso LNK4217 \(Ferramentas de Vinculador\)](../../error-messages/tool-errors/linker-tools-warning-lnk4217.md).  O vinculador gerenciar LNK4049 de aviso quando o não pode determinar que o símbolo de função importado esteve referenciado.  
  
 Os exemplos comum onde LNK4049 é gerado em vez de LNK4217 são:  
  
-   Executando vincular incremental usando a opção de [\/INCREMENTAL](../../build/reference/incremental-link-incrementally.md) .  
  
-   Executando a otimização de inteiro programa usando a opção de [\/LTCG](../../build/reference/ltcg-link-time-code-generation.md) .  
  
 Para resolver LNK4049, tente um dos seguintes:  
  
-   Remova a declaração do nome de `__declspec(dllimport)` de declaração frente do símbolo que disparou LNK4049.  Você pode procurar por símbolos dentro de uma imagem binária usando o utilitário de **DUMPBIN** .  A opção de **DUMPBIN\/SYMBOLS** exibe a tabela de símbolo de COFF da imagem.  Para obter mais informações sobre o utilitário de **DUMPBIN** , consulte [Referência de DUMPBIN](../../build/reference/dumpbin-reference.md).  
  
-   Desabilitar temporariamente a otimização incremental vincular e total de programa.  Recompilar o aplicativo irá gerar LNK4217 de aviso, que incluirá o nome da função da qual o símbolo importado foi referenciado.  Remova a declaração de `__declspec(dllimport)` de símbolo importado e habilitar vinculados ou total de programa a otimização incremental conforme necessário.  
  
 Embora o código gerado final se com comportamento corretamente, o código gerado para chamar a função importada é menos eficiente do que chamar a função diretamente.  Esse aviso não aparecerá quando você compila usando a opção [\/clr](../../build/reference/clr-common-language-runtime-compilation.md).  
  
 Para obter mais informações sobre declarações de importação e exportação de dados, consulte [dllexport, dllimport](../../cpp/dllexport-dllimport.md).  
  
## Exemplo  
 Vincular os dois seguintes módulos gerará LNK4049.  O primeiro módulo gerencie um arquivo de objeto que contém uma única função exportada.  
  
```  
// LNK4049a.cpp  
// compile with: /c  
  
__declspec(dllexport) int func()   
{  
   return 3;  
}  
```  
  
## Exemplo  
 O segundo módulo gerencie um arquivo de objeto que contém uma declaração frente à função exportada no primeiro módulo, junto com uma chamada a essa função dentro da função de `main` .  Vincular esse módulo com o primeiro módulo gerará LNK4049.  Removendo a declaração de `__declspec(dllimport)` resolverá o aviso.  
  
```  
// LNK4049b.cpp  
// compile with: /link /WX /LTCG LNK4049a.obj  
// LNK4049 expected  
  
__declspec(dllimport) int func();  
// try the following line instead  
// int func();  
  
int main()  
{  
   return func();  
}  
```  
  
## Consulte também  
 [Aviso LNK4217 \(Ferramentas de Vinculador\)](../../error-messages/tool-errors/linker-tools-warning-lnk4217.md)   
 [dllexport, dllimport](../../cpp/dllexport-dllimport.md)