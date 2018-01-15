---
title: "-E (pré-processar em stdout) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /e
dev_langs: C++
helpviewer_keywords:
- -E compiler option [C++]
- /E compiler option [C++]
- preprocessor output, copy to stdout
- preprocessor output
ms.assetid: ddbb1725-d950-4978-ab2f-30a5cd7b778c
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ed083c960421ce17c0ce61036cd05191fc12c797
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="e-preprocess-to-stdout"></a>/E (pré-processar em stdout)
Pré-processa arquivos de origem C e C++ e copia os arquivos pré-processado para o dispositivo de saída padrão.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/E  
```  
  
## <a name="remarks"></a>Comentários  
 Nesse processo, todas as diretivas de pré-processador são executadas, expansões de macro são executadas e comentários são removidos. Para preservar comentários na saída pré-processada, use o [/C (preservar comentários durante o pré-processamento)](../../build/reference/c-preserve-comments-during-preprocessing.md) também a opção de compilador.  
  
 **/E** adiciona `#line` diretivas para a saída no início e no final de cada arquivo incluído e em torno de linhas removidas por diretivas de pré-processador para compilação condicional. Essas diretivas renumerar as linhas do arquivo pré-processados. Como resultado, os erros gerados durante posteriores estágios do processamento de consultem os números de linha do arquivo original em vez de linhas no arquivo pré-processados.  
  
 O **/E** opção inibe compilação. Você deverá reenviar o arquivo pré-processados para compilação. **/E** também suprime os arquivos de saída de **/FA**, **/Fa**, e **/Fm** opções. Para obter mais informações, consulte [/FA, /Fa (listando arquivo)](../../build/reference/fa-fa-listing-file.md) e [/Fm (Mapfile de nome)](../../build/reference/fm-name-mapfile.md).  
  
 Para suprimir `#line` diretivas, use o [/EP (pré-processar para stdout sem diretivas de #line)](../../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md) opção.  
  
 Para enviar a saída pré-processada em um arquivo em vez de para `stdout`, use o [/P (pré-processar em um arquivo)](../../build/reference/p-preprocess-to-a-file.md) opção.  
  
 Para suprimir `#line` diretivas e envia a saída pré-processada em um arquivo, use **/p** e **/EP** juntos.  
  
 Não é possível usar cabeçalhos pré-compilados com o **/E** opção.  
  
 Observe que, quando o pré-processamento para um arquivo separado, espaços não são emitidos depois de tokens. Isso pode resultar em um programa inválido ou ter efeitos colaterais não intencionais. O programa a seguir é compilado com êxito:  
  
```  
#define m(x) x  
m(int)main( )  
{  
   return 0;  
}  
```  
  
 No entanto, se você compilar com:  
  
```  
cl -E test.cpp > test2.cpp  
```  
  
 `int main`em test2.cpp incorretamente será `intmain`.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **linha de comando** página de propriedades.  
  
4.  Digite a opção de compilador no **opções adicionais**caixa.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.GeneratePreprocessedFile%2A>.  
  
## <a name="example"></a>Exemplo  
 A seguinte linha de comando pré-processa `ADD.C`, preserva comentários, adiciona `#line` diretivas e exibe o resultado no dispositivo de saída padrão:  
  
```  
CL /E /C ADD.C  
```  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)