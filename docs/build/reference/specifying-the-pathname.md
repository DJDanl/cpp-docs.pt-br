---
title: Especificando o nome do caminho | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- names [C++], compiler output files
- cl.exe compiler, output files
- output files, specifying pathnames
ms.assetid: 7a6595ce-3383-44ae-957a-466bfa29c343
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a2dd121909fbe0aa2f9305b7bd5779b995a69719
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="specifying-the-pathname"></a>Especificando o nome de demarcador
Cada opção de arquivo de saída aceita um *pathname* argumento que pode especificar um local e um nome para o arquivo de saída. O argumento pode incluir um nome de unidade, o diretório e o nome do arquivo. Não são permitidos espaços entre a opção e o argumento.  
  
 Se *pathname* inclui um nome de arquivo sem uma extensão, o compilador dá a saída de uma extensão padrão. Se *pathname* inclui um diretório, mas nenhum nome de arquivo, o compilador cria um arquivo com um nome padrão no diretório especificado. O nome padrão é baseado no nome base do arquivo de origem e uma extensão padrão com base no tipo de arquivo de saída. Se você não incluir *pathname* totalmente, o compilador cria um arquivo com um nome padrão em um diretório padrão.  
  
 Como alternativa, o *pathname* argumento pode ser um nome de dispositivo (AUX, CON, PRN ou NUL) em vez de um nome de arquivo. Não use um espaço entre a opção e o nome do dispositivo ou um vírgula como parte do nome do dispositivo.  
  
|Nome do dispositivo|Representa|  
|-----------------|----------------|  
|AUX|Dispositivo auxiliar|  
|CON|Console|  
|PRN|Impressora|  
|NUL|Dispositivo do nulo (nenhum arquivo criado)|  
  
## <a name="example"></a>Exemplo  
 A linha de comando a seguir envia um arquivo de mapa para a impressora:  
  
```  
CL /FmPRN HELLO.CPP  
```  
  
## <a name="see-also"></a>Consulte também  
 [Arquivo de saída (/ F) opções](../../build/reference/output-file-f-options.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)