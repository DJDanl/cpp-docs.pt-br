---
title: "/BASE (endere&#231;o b&#225;sico) | Microsoft Docs"
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
  - "/base"
  - "VC.Project.VCLinkerTool.BaseAddress"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /BASE"
  - "símbolo @ para endereço básico"
  - "símbolo de arroba para endereço básico"
  - "endereços básicos [C++]"
  - "opção de vinculador BASE"
  - "opção de vinculador -BASE"
  - "DLLs [C++], vinculando"
  - "variáveis de ambiente [C++], LIB"
  - "arquivos executáveis [C++], endereço básico"
  - "tamanho de endereço chave"
  - "variável de ambiente LIB"
  - "programas [C++], endereço básico"
  - "programas [C++], impedindo realocação"
  - "ponto e vírgula [C++], especificador"
ms.assetid: 00b9f6fe-0bd2-4772-a69c-7365eb199069
caps.latest.revision: 15
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /BASE (endere&#231;o b&#225;sico)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/BASE:{address[,size] | @filename,key}  
```  
  
 A opção BASE define um endereço base para o programa, substituindo o local padrão para um arquivo DLL ou .exe. O endereço de base padrão para um arquivo .exe é 0x400000 para imagens de 32 bits ou 0x140000000 para imagens de 64 bits. Para uma DLL, o endereço base padrão é 0x10000000 para imagens de 32 bits ou 0x180000000 para imagens de 64 bits. Em sistemas operacionais que não suportam a randomização de layout de espaço de endereço \(ASLR\), ou quando a opção \/DYNAMICBASE:NO foi definida, o sistema operacional primeiro tenta carregar um programa em seu especificado ou o endereço base do padrão. Se o espaço em disco não estiver disponível, o sistema realoca o programa. Para evitar a realocação, use o [\/Fixed](../../build/reference/fixed-fixed-base-address.md) opção.  
  
 O vinculador emite um erro se *endereço* não é um múltiplo de 64K. Opcionalmente, você pode especificar o tamanho do programa; o vinculador emite um aviso se o programa não pode se ajustar no tamanho especificado.  
  
 Na linha de comando, outra maneira de especificar o endereço base é usando um arquivo de resposta de endereço base. Um arquivo de resposta de endereço base é um arquivo de texto que contém os endereços base e tamanhos opcionais de todas as DLLs seu programa será usado e uma chave de texto exclusivo para cada endereço de base. Para especificar um endereço base usando um arquivo de resposta, use um sinal de arroba \(@\) seguido do nome do arquivo de resposta, *filename*, seguido por uma vírgula, o `key` valor para o endereço base usar no arquivo. O vinculador procura *filename* o caminho especificado, ou se nenhum caminho for especificado, nos diretórios especificados na variável de ambiente LIB. Cada linha no *filename* representa uma DLL e tem a seguinte sintaxe:  
  
```  
  
key address [size] ;comment  
```  
  
 O `key` é uma cadeia de caracteres alfanuméricos e não diferencia maiúsculas de minúsculas. Ele é normalmente o nome de uma DLL, mas ele não precisa ser. O `key` é seguido por uma base de *endereço* na notação decimal, hexadecimal ou de linguagem C e um máximo opcional `size`. Todos os três argumentos são separados por tabulações ou espaços. O vinculador emite um aviso se especificado `size` é menor que o espaço de endereço virtual requerido pelo programa. A `comment` é especificado por um ponto e vírgula \(;\) e pode ser na mesma ou em uma linha separada. O vinculador ignora todo o texto de vírgula no final da linha. Este exemplo mostra parte de um arquivo:  
  
```  
main   0x00010000    0x08000000    ; for PROJECT.exe  
one    0x28000000    0x00100000    ; for DLLONE.DLL  
two    0x28100000    0x00300000    ; for DLLTWO.DLL  
```  
  
 Se o arquivo que contém essas linhas é chamado de DLLs, o comando de exemplo a seguir aplica essas informações:  
  
```  
link dlltwo.obj /dll /base:@dlls.txt,two  
```  
  
## Comentários  
 Por motivos de segurança, a Microsoft recomenda que você use o [\/DYNAMICBASE](../../build/reference/dynamicbase-use-address-space-layout-randomization.md) opção em vez de especificar os endereços base para seus executáveis. Isso gera uma imagem executável que possa ter REBASE aleatória no tempo de carregamento usando o recurso de aleatória \(ASLR\) de layout de espaço de endereço do Windows. A opção de \/DYNAMICBASE está ativada por padrão.  
  
 Outra maneira de definir o endereço base é usando o *BASE* argumento em uma [nome](../Topic/NAME%20\(C-C++\).md) ou [biblioteca](../../build/reference/library.md) instrução. O \/BASE e [\/DLL](../../build/reference/dll-build-a-dll.md) opções são equivalentes ao conjunto de **biblioteca** instrução.  
  
### Para definir essa opção de vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter detalhes, consulte [configuração de propriedades de projeto Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Expanda o **vinculador** pasta.  
  
3.  Escolha o **Avançado** página de propriedades.  
  
4.  Modificar o **Endereço Base** propriedade.  
  
### Para definir essa opção de vinculador programaticamente  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.BaseAddress%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)