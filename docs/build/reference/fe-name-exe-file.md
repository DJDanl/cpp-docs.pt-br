---
title: -Fe (nomear o arquivo EXE) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /fe
dev_langs: C++
helpviewer_keywords:
- -Fe compiler option [C++]
- executable files, renaming
- rename file compiler option [C++]
- /Fe compiler option [C++]
- Fe compiler option [C++]
ms.assetid: 49f594fd-5e94-45fe-a1bf-7c9f2abb6437
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: b66c473c49527dff395d206594a314b527c4f914
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="fe-name-exe-file"></a>/Fe (nomear arquivo EXE)
Especifica um nome e um diretório para o arquivo de .exe ou DLL criada pelo compilador.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Fepathname  
```  
  
## <a name="remarks"></a>Comentários  
 Sem essa opção, o compilador dá ao arquivo um nome padrão usando o nome base do arquivo de origem ou de objeto primeiro especificado na linha de comando e a extensão .exe ou. dll.  
  
 Se você especificar o[/c (compilar sem vinculação)](../../build/reference/c-compile-without-linking.md)para compilar sem vinculação, **/Fe** não tem nenhum efeito.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **geral**página de propriedades.  
  
4.  Modificar o **arquivo de saída** propriedade.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.OutputFile%2A>.  
  
## <a name="example"></a>Exemplo  
 A linha de comando a seguir compila e vincula a todos os arquivos de origem C no diretório atual. O arquivo executável resultante é denominado PROCESS.exe e é criado no diretório C:\BIN.  
  
```  
CL /FeC:\BIN\PROCESS *.C  
```  
  
## <a name="example"></a>Exemplo  
 A linha de comando a seguir cria um arquivo executável em `C:\BIN` com o mesmo nome base como o primeiro arquivo de origem ou de objeto:  
  
```  
CL /FeC:\BIN\ *.C  
```  
  
## <a name="see-also"></a>Consulte também  
 [Arquivo de saída (/ F) opções](../../build/reference/output-file-f-options.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)   
 [Especificando o nome de caminho](../../build/reference/specifying-the-pathname.md)