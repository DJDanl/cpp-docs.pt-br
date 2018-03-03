---
title: /FA, /Fa (listando arquivo) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCCLWCECompilerTool.AssemblerListingLocation
- VC.Project.VCCLCompilerTool.ConfigureASMListing
- VC.Project.VCCLWCECompilerTool.AssemblerOutput
- VC.Project.VCCLCompilerTool.AssemblerListingLocation
- /fa
- VC.Project.VCCLCompilerTool.AssemblerOutput
- VC.Project.VCCLCompilerTool.UseUnicodeForAssemblerListing
dev_langs:
- C++
helpviewer_keywords:
- FA compiler option [C++]
- /FA compiler option [C++]
- -FA compiler option [C++]
- listing file type
- assembly-only listing
ms.assetid: c7507d0e-c69d-44f9-b8e2-d2c398697402
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e0cd569cf16e7b2a14faaa119eacaef0994d09dc
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="fa-fa-listing-file"></a>/FA, /Fa (listando arquivo)
Cria um arquivo de lista que contém o código do assembler.  
  
## <a name="syntax"></a>Sintaxe  
  
> **/FA**[**c**\][**s**\][**u**]  
> **/FA**_pathname_  
  
## <a name="remarks"></a>Comentários  
O `/FA` opção de compilador gera um arquivo de listagem do assembler para cada unidade de tradução na compilação, que geralmente corresponde a um arquivo de código-fonte C ou C++. Por padrão, somente assembler está incluído no arquivo de listagem, que é codificado como ANSI. Opcional `c`, `s`, e `u` argumentos para `/FA` controle se código da máquina ou código-fonte são saída junto com o assembler listando e se a listagem é codificada como UTF-8.  
  
Por padrão, cada arquivo de listagem recebe o mesmo nome base do arquivo de origem e tem uma extensão. ASM. Quando o código de máquina está incluído usando o `c` opção, o arquivo de listagem tem uma extensão. Cod. Você pode alterar o nome e a extensão do arquivo de listagem e o diretório em que ele é criado usando o `/Fa` opção.  

### <a name="fa-arguments"></a>Argumentos /FA  
nenhum  
Somente o idioma assembler está incluído na lista.  
  
`c`  
Opcional. Inclui o código de computador na lista.  
  
`s`  
Opcional. Inclui o código-fonte na lista.  
  
`u`Opcional. Codifica o arquivo de listagem no formato UTF-8 e inclui um marcador de ordem de byte. Por padrão, o arquivo é codificado como ANSI. Use `u` para criar um arquivo de listagem exibe corretamente em qualquer sistema, ou se você estiver usando o Unicode de arquivos de código de origem como entrada para o compilador.  
  
Se ambos os `s` e `u` são especificadas e, se uma fonte de arquivo de código usa a codificação Unicode diferente de UTF-8 e, em seguida, as linhas de código no arquivo. ASM talvez não sejam exibidos corretamente.  
  
### <a name="fa-argument"></a>/FA argumento  
nenhum  
Um *fonte*. ASM arquivo é criado para cada arquivo de código fonte na compilação.  
  
*nome de arquivo* um arquivo de listagem chamado *filename*. ASM é colocado no diretório atual. Isso só é válido durante a compilação de um arquivo de código de origem única.  
  
*filename.Extension*  
Um arquivo de listagem chamado *filename.extension* é colocado no diretório atual. Isso só é válido durante a compilação de um arquivo de código de origem única.  
  
*diretório*\  
Um *source_file*. ASM arquivo é criado e inserido no especificado *diretório* para cada arquivo de código fonte na compilação. Observe a barra invertida necessária. São permitidos apenas os caminhos do disco atual.  
  
*diretório*\\*filename* um arquivo de listagem chamado *filename*. ASM é colocado em especificado *diretório*. Isso só é válido durante a compilação de um arquivo de código de origem única.  
  
*diretório*\\*filename.extension*  
Um arquivo de listagem chamado *filename.extension* é colocado no especificado *diretório*. Isso só é válido durante a compilação de um arquivo de código de origem única.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Abra o **C/C++** pasta e selecione o **arquivos de saída** página de propriedades.  
  
3.  Modificar o **saída do Assembler** propriedade para definir o `/FAc` e `/FAs` opções assembler, máquina e código-fonte. Modificar o **usar Unicode para listagem de Assembler** propriedade para definir o `/FAu` opção de saída ANSI ou UTF-8. Modificar o **local da lista ASM** para definir o `/Fa` opção para listar o nome de arquivo e o local.  
  
Observe que configuração ambos **saída do Assembler** e **usar Unicode para listagem de Assembler** propriedades podem causar [de linha de comando aviso D9025](../../error-messages/tool-errors/command-line-warning-d9025.md). Para combinar essas opções no IDE, use o **opções adicionais** campo o **linha de comando** página de propriedade em vez disso.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AssemblerListingLocation%2A> ou <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AssemblerOutput%2A>. Para especificar `/FAu`, consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="example"></a>Exemplo  
A linha de comando a seguir produz uma fonte combinada e listagem de código de máquina chamado HELLO.cod:  
  
```  
CL /FAcs HELLO.CPP  
```  
  
## <a name="see-also"></a>Consulte também  
 [Arquivo de saída (/ F) opções](../../build/reference/output-file-f-options.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)   
 [Especificando o nome de caminho](../../build/reference/specifying-the-pathname.md)