---
title: RW2003 de erro do compilador de recurso | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- RW2003
dev_langs:
- C++
helpviewer_keywords:
- RW2003
ms.assetid: 9dc0ba70-6776-4aef-b316-5f1711d8e42e
caps.latest.revision: 6
author: corob-msft
ms.author: corob
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: c616e0cdad0a135c328241648d22ded7687e1076
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="resource-compiler-error-rw2003"></a>Erro RW2003 (compilador de recurso)
Erro de geração  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  **Erro: Arquivo de recurso de arquivo de Bitmap não está no formato 3.00**  
  
     Bitmaps usando o formato Windows versão 2.x não podem ser usados em arquivos de recursos de versão 3.x. O bitmap deve ser redesenhado ou convertido para o formato 3. x.  
  
2.  **Erro: DIB antigo no nome de recurso. Passe-o por meio de SDKPAINT**  
  
     Um Bitmap independente de dispositivo (DIB) no recurso especificado não é compatível com o formato Windows 3.0. O bitmap deve ser redesenhado ou convertido para o formato 3. x.  
  
3.  **Erro: Nome de recurso de arquivo de recurso não está no formato 3.00**  
  
     Um ícone ou cursor no recurso especificado usado um formato de uma versão anterior do Windows. O ícone ou cursor deve ser redesenhado ou convertido para o formato 3. x.  
  
4.  **Formato desconhecido de cabeçalho DIB**  
  
     O cabeçalho de bitmap não é uma estrutura BITMAPCOREHEADER ou BITMAPINFOHEADER.  
  
5.  **Não foi possível inicializar as informações de símbolo**  
  
     Esse erro ocorre apenas no Visual C++. A causa provável é que você tenha muitos arquivos abertos ou você não pode abrir ou gravar os arquivos de dados necessários para o Visual C++ importar os símbolos no script. Visual C++ tenta criar esses arquivos no diretório especificado pelo **TMP** variável de ambiente ou o diretório atual, se nenhum for especificado.  
  
6.  **Não é possível salvar as informações de símbolo**  
  
     Esse erro ocorre apenas no Visual C++. A causa provável é que você tenha muitos arquivos abertos ou você não pode fechar ou gravar os arquivos de dados necessários para o Visual C++ importar os símbolos no script. Visual C++ tenta usar esses arquivos no diretório especificado o **TMP** variável de ambiente ou o diretório atual, se nenhum for especificado.  
  
7.  **Arquivo de recurso do arquivo de bitmap não está no formato 2,03**  
  
     Um bitmap usado em um formato anterior à versão 2.03. O bitmap deve ser convertido ou reemitida usando o formato de versão 3.00 ou posterior.  
  
8.  **Recurso muito grande**  
  
     Para um recurso do Windows 3.1 não pode exceder aproximadamente 65000 bytes. Se o recurso, em seguida, você não poderá compilá-lo com o Visual C++ ou o compilador de recurso de linha de comando. Esse limite não se aplica a cursores, ícones, bitmaps ou outros recursos com base em arquivo.  
  
9. **Arquivo de recurso não está no formato 3.00**  
  
     Um ícone ou cursor usado um formato anterior à versão 3,00. O recurso deve ser convertido ou reemitida usando o formato de versão 3.00 ou posterior.  
  
10. **Não é possível abrir o arquivo temporário**  
  
     O recurso de compilador/Visual C++ não pôde abrir um arquivo temporário. A causa provável é que você não tem permissões de gravação para o diretório ou o diretório não existe. O recurso de compilador/Visual C++ tenta usar esses arquivos no diretório especificado pelo **TMP** variável de ambiente ou o diretório atual, se nenhum for especificado.
