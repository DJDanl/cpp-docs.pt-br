---
title: "-BASE (endereço Base) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /base
- VC.Project.VCLinkerTool.BaseAddress
dev_langs: C++
helpviewer_keywords:
- base addresses [C++]
- programs [C++], preventing relocation
- semicolon [C++], specifier
- -BASE linker option
- key address size
- environment variables [C++], LIB
- programs [C++], base address
- LIB environment variable
- BASE linker option
- DLLs [C++], linking
- /BASE linker option
- '@ symbol for base address'
- executable files [C++], base address
- at sign symbol for base address
ms.assetid: 00b9f6fe-0bd2-4772-a69c-7365eb199069
caps.latest.revision: "15"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: f59837f5c64e694893b941b1fe2e507e1a05938c
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="base-base-address"></a>/BASE (endereço básico)
```  
/BASE:{address[,size] | @filename,key}  
```  
  
 A opção BASE define um endereço base para o programa, substituindo o local padrão para um arquivo DLL ou .exe. O endereço base padrão para um arquivo .exe é 0x400000 para imagens de 32 bits ou 0x140000000 para imagens de 64 bits. Para uma DLL, o endereço base padrão é 0x10000000 para imagens de 32 bits ou 0x180000000 para imagens de 64 bits. Em sistemas operacionais que não dão suporte a aleatória de layout de espaço de endereço (ASLR), ou quando a opção /DynamicBase: no foi definida, o sistema operacional primeiro tenta carregar um programa em seu especificado ou o endereço base padrão. Se o espaço em disco não estiver disponível, o sistema realoca o programa. Para evitar a realocação, use o [/Fixed](../../build/reference/fixed-fixed-base-address.md) opção.  
  
 O vinculador emitirá um erro se *endereço* não é um múltiplo de 64 K. Opcionalmente, você pode especificar o tamanho do programa; o vinculador emite um aviso se o programa não pode se ajustar ao tamanho especificado.  
  
 Na linha de comando, outra maneira de especificar o endereço base é usando um arquivo de resposta de endereço base. Um arquivo de resposta de endereço base é um arquivo de texto que contém os endereços de base e os tamanhos opcionais de todas as DLLs usará seu programa e uma chave de texto exclusiva para cada endereço de base. Para especificar um endereço base usando um arquivo de resposta, use um sinal de arroba (@) seguido do nome do arquivo de resposta, *filename*, seguido por uma vírgula, em seguida, o `key` valor para o endereço base usar no arquivo. O vinculador procura *filename* o caminho especificado, ou se nenhum caminho for especificado, nos diretórios especificados na variável de ambiente LIB. Cada linha no *filename* representa um DLL e tem a seguinte sintaxe:  
  
```  
  
key address [size] ;comment  
```  
  
 O `key` é uma cadeia de caracteres alfanuméricos e não diferencia maiusculas de minúsculas. Ele é normalmente o nome de uma DLL, mas ele não precisa ser. O `key` é seguido por uma base de *endereço* na notação decimal, hexadecimal ou de linguagem C e um máximo opcional `size`. Todos os três argumentos são separados por tabulações ou espaços. O vinculador emite um aviso se especificado `size` é menor que o espaço de endereço virtual exigido pelo programa. Um `comment` especificado por um ponto e vírgula (;) e pode ser na mesma ou em uma linha separada. O vinculador ignora todo o texto de vírgula ao final da linha. Este exemplo mostra a parte de um arquivo:  
  
```  
main   0x00010000    0x08000000    ; for PROJECT.exe  
one    0x28000000    0x00100000    ; for DLLONE.DLL  
two    0x28100000    0x00300000    ; for DLLTWO.DLL  
```  
  
 Se o arquivo que contém essas linhas é chamado DLLs, o comando de exemplo a seguir se aplica a essas informações:  
  
```  
link dlltwo.obj /dll /base:@dlls.txt,two  
```  
  
## <a name="remarks"></a>Comentários  
 Por motivos de segurança, a Microsoft recomenda que você use o [/DYNAMICBASE](../../build/reference/dynamicbase-use-address-space-layout-randomization.md) opção em vez de especificar endereços de base para seus executáveis. Isso gera uma imagem executável que pode ser baseada aleatoriamente de novo no tempo de carregamento usando o recurso do aleatória (ASLR) de layout do espaço de endereço do Windows. A opção de /DYNAMICBASE está ativada por padrão.  
  
 Outra maneira de definir o endereço base é usando o *BASE* argumento em uma [nome](../../build/reference/name-c-cpp.md) ou [biblioteca](../../build/reference/library.md) instrução. O /BASE e [/DLL](../../build/reference/dll-build-a-dll.md) opções juntos são equivalentes para o **biblioteca** instrução.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Expanda o **vinculador** pasta.  
  
3.  Escolha o **avançado** página de propriedades.  
  
4.  Modificar o **endereço Base** propriedade.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.BaseAddress%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)