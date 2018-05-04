---
title: Diretivas de pré-processamento de makefile | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
f1_keywords:
- '!UNDEF'
- '!INCLUDE'
- '!IFNDEF'
- '!MESSAGE'
dev_langs:
- C++
helpviewer_keywords:
- ERROR directive
- '!MESSAGE directive'
- IF directive
- '!UNDEF directive'
- IFDEF directive
- '!ELSEIF directive'
- '!IFDEF directive'
- '!IF directive'
- UNDEF directive
- '!CMDSWITCHES directive'
- ENDIF directive
- directives, makefile preprocessing
- INCLUDE directive
- IFNDEF directive
- preprocessing directives, makefiles
- '!IFNDEF directive'
- ELSEIFNDEF directive
- NMAKE program, expressions
- ELSEIF directive
- '!ERROR directive'
- '!ENDIF directive'
- MESSAGE directive
- '!INCLUDE directive'
- '!ELSEIFNDEF directive'
- CMDSWITCHES directive
- '!ELSEIFDEF directive'
- '!ELSE directive'
- NMAKE program, preprocessor directives
- makefiles, preprocessing directives
- ELSE directive
- ELSEIFDEF directive
ms.assetid: bcedeccb-d981-469d-b9e8-ab5d097fd8c2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6a84557388f521fb6c70c33ce6814ce33a5f6a1d
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="makefile-preprocessing-directives"></a>Diretivas de pré-processamento de makefile
Diretivas de pré-processamento não diferenciam maiusculas de minúsculas. O ponto de exclamação (!) inicial deve aparecer no começo da linha. Zero ou mais espaços ou guias podem aparecer após o ponto de exclamação, para fins de recuo.  
  
 **! CMDSWITCHES**  
 {**+** &#124; **-**}*opção*... Transforma cada *opção* listados ativado ou desativado. Tabulações ou espaços devem aparecer antes do + ou - operador; Nenhum pode aparecer entre o operador e o [opção letras](../build/nmake-options.md). Letras não diferenciam maiusculas de minúsculas e estão especificadas sem uma barra (/). Para algumas opções e outras pessoas de fora, use separadas especificações de **! CMDSWITCHES**.  
  
 Somente /D, I, /N e /S pode ser usada em um makefile. Tools.ini, todas as opções são permitidas exceto /F, /HELP, /NOLOGO, /x, e /?. As alterações especificadas em um bloco de descrição não entram em vigor até o próximo bloco de descrição. Essa diretiva atualiza **MAKEFLAGS**; as alterações são herdadas durante recursão se **MAKEFLAGS** for especificado.  
  
 **! Erro***texto*   
 Exibe *texto* erro U1050 e, em seguida, é interrompida NMAKE, mesmo se /K, /, **. Ignorar**, **! CMDSWITCHES**, ou o modificador de comando de traço (-) é usado. Espaços ou guias antes *texto* são ignorados.  
  
 **! MENSAGEM***texto*   
 Exibe *texto* para a saída padrão. Espaços ou guias antes *texto* são ignorados.  
  
 **! INCLUIR**[ **\<**] *filename*[ **>**]  
 Lê *filename* como um makefile, em seguida, continua com o makefile atual. NMAKE procura *filename* primeiro no diretório atual ou especificado, em seguida, recursivamente por meio de diretórios de qualquer pai makefiles, em seguida, se *filename* é colocado entre colchetes angulares (\<>), nos diretórios especificados pelo **incluir** macro, que é inicialmente definida como a variável de ambiente INCLUDE. Útil para passar **. SUFIXOS** configurações, **. PRECIOSOS**e as regras de inferência em makefiles recursiva.  
  
 **! SE**  `constantexpression`  
 Processa as instruções entre **! Se** e a próxima **! ELSE** ou `!ENDIF` se `constantexpression` for avaliada como um valor diferente de zero.  
  
 **! IFDEF***nomedamacro*   
 Processa as instruções entre `!IFDEF` e a próxima **! ELSE** ou `!ENDIF` se *nomedamacro* está definido. Uma macro nulo é considerada a ser definido.  
  
 **! IFNDEF***nomedamacro*   
 Processa as instruções entre **! IFNDEF** e a próxima **! ELSE** ou `!ENDIF` se *nomedamacro* não está definido.  
  
 **! ELSE**[**se** *constantexpression* &#124; **IFDEF** *nomedamacro* &#124; **IFNDEF**  *nomedamacro*]  
 Processa as instruções entre **! ELSE** e o próximo `!ENDIF` se anterior **! Se**, `!IFDEF`, ou **! IFNDEF** instrução é avaliada como zero. As palavras-chave opcional oferecem mais controle de pré-processamento.  
  
 **! ELSEIF**  
 Sinônimo de **! Se outro**.  
  
 **! ELSEIFDEF**  
 Sinônimo de **! ELSE IFDEF**.  
  
 **! ELSEIFNDEF**  
 Sinônimo de **! ELSE IFNDEF**.  
  
 `!ENDIF`  
 Marca o fim de um **! Se**, `!IFDEF`, ou **! IFNDEF** bloco. Qualquer texto após `!ENDIF` na mesma linha é ignorado.  
  
 **! UNDEF***nomedamacro*   
 Remoções de definições de *nomedamacro*.  
  
## <a name="see-also"></a>Consulte também  
 [Pré-processamento de makefile](../build/makefile-preprocessing.md)