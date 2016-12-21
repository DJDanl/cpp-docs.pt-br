---
title: "/E (pr&#233;-processar em stdout) | Microsoft Docs"
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
  - "/e"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /E (C++)"
  - "Opção de compilador -E [C++]"
  - "saída de pré-processador"
  - "saída de pré-processador, copiar em stdout"
ms.assetid: ddbb1725-d950-4978-ab2f-30a5cd7b778c
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /E (pr&#233;-processar em stdout)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Preprocesses arquivos de origem de 2.0 C e C\+\+ e copia os arquivos pré\-processados para o dispositivo de saída padrão.  
  
## Sintaxe  
  
```  
/E  
```  
  
## Comentários  
 Neste processo, todas as políticas de pré\-processador são realizadas, as expansões macro são executadas, e os comentários são removidos.  Para preservar comentários na saída pré\-processados, use a opção do compilador de [\/C \(preservar comentários durante o pré\-processamento\)](../../build/reference/c-preserve-comments-during-preprocessing.md) também.  
  
 adiciona**\/E** políticas de `#line` à saída no início e o término de cada arquivo incluído e delimitando as linhas removidas por políticas de pré\-processador para a compilação condicional.  Essas políticas renumber as linhas do arquivo pré\-processados.  No resultado, os erros gerados durante estados avançadas de processamento se referem aos números de linhas do arquivo de origem original em vez de linhas no arquivo pré\-processados.  
  
 A opção de **\/E** suprime a compilação.  Você deve enviar novamente o arquivo pré\-processados para a compilação.  **\/E** também elimina os arquivos de saída de **\/FA**, de **\/Fa**, e as opções de **\/Fm** .  Para obter mais informações, consulte [\/FA, \/Fa \(listando arquivo\)](../../build/reference/fa-fa-listing-file.md) e [\/Fm \(mapfile de nome\)](../Topic/-Fm%20\(Name%20Mapfile\).md).  
  
 Para suprimir políticas de `#line` , use a opção de [\/EP \(pré\-processar para stdout sem diretivas \#line\)](../../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md) em vez disso.  
  
 Para enviar a saída pré\-processados para um arquivo em vez a `stdout`, use a opção de [\/P \(pré\-processar em um arquivo\)](../../build/reference/p-preprocess-to-a-file.md) em vez disso.  
  
 Para suprimir políticas de `#line` e enviar junto a saída pré\-processados para um arquivo, use **\/P** e um **\/EP** .  
  
 Você não pode usar cabeçalhos pré\-compilados com a opção de **\/E** .  
  
 Observe que a eles em um arquivo separado, espaços não são emitidos depois de tokens.  Isso pode resultar em um programa ilegal ou ter efeitos colaterais não intencionais.  O seguinte programa cria com êxito:  
  
```  
#define m(x) x  
m(int)main( )  
{  
   return 0;  
}  
```  
  
 No entanto, se você criar com:  
  
```  
cl -E test.cpp > test2.cpp  
```  
  
 `int main` em test2.cpp será `intmain`incorretamente.  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **Linha de Comando**.  
  
4.  Digite a opção do compilador na caixade **Opções Adicionais**.  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.GeneratePreprocessedFile%2A>.  
  
## Exemplo  
 A linha de comando a seguir preprocesses `ADD.C`, preserva comentários, adiciona políticas de `#line` , e exibe o resultado no dispositivo de saída padrão:  
  
```  
CL /E /C ADD.C  
```  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)