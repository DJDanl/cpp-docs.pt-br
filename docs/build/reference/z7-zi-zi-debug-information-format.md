---
title: "-/Z7, - Zi, - ZI (formato de informações de depuração) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCCLCompilerTool.DebugInformationFormat
- /zi
- /z7
- VC.Project.VCCLWCECompilerTool.DebugInformationFormat
dev_langs: C++
helpviewer_keywords:
- C7 compatible compiler option [C++]
- -Zl compiler option [C++]
- Debug Information Format compiler option
- ZI compiler option
- -Zi compiler option [C++]
- /ZI compiler option [C++]
- Z7 compiler option [C++]
- debugging [C++], debug information files
- Zi compiler option [C++]
- none compiler option [C++]
- /Zi compiler option [C++]
- program database compiler option [C++]
- full symbolic debugging information
- /Z7 compiler option [C++]
- line numbers only compiler option [C++]
- cl.exe compiler, debugging options
- -Z7 compiler option [C++]
ms.assetid: ce9fa7e1-0c9b-47e3-98ea-26d1a16257c8
caps.latest.revision: "21"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 0b80339192a7d335b0989ac8a67446c0f5716a76
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="z7-zi-zi-debug-information-format"></a>/Z7, /Zi, /ZI (depurar formato de informações)
Selecione o tipo de informação de depuração criado para o programa e se essas informações são mantidas em arquivos de objeto (. obj) ou em um banco de dados do programa (PDB).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Z{7|i|I}  
```  
  
## <a name="remarks"></a>Comentários  
 As opções são descritas na tabela a seguir.  
  
 Nenhum  
 Não produz nenhuma informação de depuração para a compilação é mais rápida.  
  
 **/Z7**  
 Produz um arquivo. obj que contém informações de depuração simbólicas completas para uso com o depurador. As informações de depuração simbólicas incluem os nomes e tipos de variáveis, bem como funções e os números de linha. Nenhum arquivo. PDB é produzido.  
  
 Para distribuidores de bibliotecas de terceiros, há uma vantagem de não ter um arquivo. PDB. No entanto, os arquivos. obj para os cabeçalhos pré-compilados são necessários durante a fase de link e depuração. Se houver apenas digite informações (e nenhum código) nos arquivos de objeto. pch, você também precisará compilar com [/Yl (injetar referência PCH para biblioteca de depuração)](../../build/reference/yl-inject-pch-reference-for-debug-library.md).  
  
 **/Zi**  
 Produz um banco de dados do programa (PDB) que contém informações de tipo e informações simbólicas de depuração para uso com o depurador. As informações de depuração simbólicas incluem os nomes e tipos de variáveis, bem como funções e os números de linha.  
  
 **/Zi** não afeta otimizações. No entanto, **/Zi** implicam **/Debug**; consulte [/DEBUG (gerar informações de depuração)](../../build/reference/debug-generate-debug-info.md) para obter mais informações.  
  
 Informações de tipo são colocadas no arquivo. PDB e não no arquivo. obj.  
  
 Você pode usar [/GM (habilitar mínimo recriar) de manual](../../build/reference/gm-enable-minimal-rebuild.md) com **/Zi**, enquanto **/GM manual** não está disponível durante a compilação com **/Z7**.  
  
 Ao compilar com **/Zi** e **/clr**, o <xref:System.Diagnostics.DebuggableAttribute> atributo não será realizado nos metadados do assembly; você deve especificá-lo no código-fonte, se desejar. Esse atributo pode afetar o desempenho de tempo de execução do aplicativo. Para obter mais informações sobre como o atributo Depurável afeta o desempenho e como você pode modificar o impacto no desempenho, consulte [facilitando uma imagem para depuração](/dotnet/framework/debug-trace-profile/making-an-image-easier-to-debug).  
  
 **/ZI**  
 Produz um banco de dados do programa, como descrito acima, em um formato que suporta o recurso Editar e continuar. Se você quiser usar Editar e continuar a depuração, você deve usar essa opção. Como a maioria das otimizações são incompatíveis com editar e continuar, usando **/ZI** desativa qualquer `#pragma optimize` no seu código.  
  
 **/Zi** faz com que [/Gy (habilitar vinculação do nível de função)](../../build/reference/gy-enable-function-level-linking.md) e [/FC (completo caminho do arquivo de código fonte no diagnóstico)](../../build/reference/fc-full-path-of-source-code-file-in-diagnostics.md) a ser usado na sua compilação.  
  
 **/Zi** não é compatível com [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md).  
  
> [!NOTE]
>  **/Zi** só está disponível nos compiladores direcionamento processadores x86 e x64; essa opção de compilador não está disponível nos compiladores direcionamento processadores ARM.  
  
 O compilador nomeia o banco de dados do programa *projeto*. PDB. Se você compilar um arquivo sem um projeto, o compilador cria um banco de dados denominado VC*x*0.pdb., onde *x* é a versão principal do [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)] em uso. O compilador incorpora o nome do PDB em cada arquivo. obj criado usando essa opção, apontando o depurador para o local das informações simbólicos e número da linha. Quando você usar essa opção, os arquivos. obj serão menores, porque as informações de depuração é armazenada no arquivo. PDB em vez de em arquivos. obj.  
  
 Se você criar uma biblioteca de objetos que foram compilados usando essa opção, o arquivo. PDB associado deve estar disponível quando a biblioteca está vinculada a um programa. Portanto, se você distribuir a biblioteca, você deve distribuir o PDB.  
  
 Para criar uma biblioteca que contém informações de depuração sem o uso de arquivos. PDB, você deve selecionar C do compilador compatível com 7.0 (**/Z7**) opção. Se você usar as opções de cabeçalhos pré-compilados, as informações de cabeçalho pré-compilado e o restante do código-fonte de depuração é colocada no PDB. O **/Yd** opção é ignorada quando a opção de banco de dados do programa é especificada.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **geral** página de propriedades.  
  
4.  Modificar o **formato informações de depuração** propriedade.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.DebugInformationFormat%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)