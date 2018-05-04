---
title: arquivos. netmodule como entrada de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- MSIL linking
- linking [C++], modules
- .netmodules
- modules, Visual C++
ms.assetid: a4bcbe8a-4255-451d-853b-f88cfd82f4e1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 23a1ecdff483118d92ac2c5fd01c24e8f2599bc6
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="netmodule-files-as-linker-input"></a>Arquivos .netmodule como entrada de vinculador
link.exe agora aceita MSIL obj e. netmodules como entrada. O arquivo de saída produzido pelo vinculador será um assembly ou um. netmodule com nenhuma dependência de tempo de execução de qualquer um dos. obj ou. netmodules que foram inseridos para o vinculador.  
  
 . netmodules são criados pelo compilador do Visual C++ com [/LN (criar o módulo MSIL)](../../build/reference/ln-create-msil-module.md) ou pelo vinculador com [/NOASSEMBLY (criar um módulo MSIL)](../../build/reference/noassembly-create-a-msil-module.md). .objs sempre são criados em uma compilação do Visual C++. Para outros compiladores do Visual Studio, use o **/target: Module** opção de compilador.  
  
  Você precisará passar para o vinculador do arquivo. obj de compilação do Visual C++ que criou o. netmodule. Passando um. netmodule não tem suporte porque o **/clr: pure** e **/CLR: safe** opções do compilador são preteridas no Visual Studio 2015 e serão removidas em uma versão futura do compilador.   
  
 Para obter informações sobre como chamar o vinculador da linha de comando, consulte [sintaxe de linha de comando do vinculador](../../build/reference/linker-command-line-syntax.md), [código C/C++ compilar na linha de comando](../../build/building-on-the-command-line.md), e [definir o caminho e as variáveis de ambiente para Compilações de linha de comando](../../build/setting-the-path-and-environment-variables-for-command-line-builds.md).  
  
 Passando um arquivo. netmodule ou. dll para o vinculador que foi compilado pelo compilador do Visual C++ com **/clr** pode resultar em um erro de vinculador. Para obter mais informações, consulte [escolher o formato de arquivos de entrada. netmodule](../../build/reference/choosing-the-format-of-netmodule-input-files.md).  
  
 O vinculador aceita arquivos. obj nativo, bem como arquivos. obj MSIL compilados com **/clr**. Ao passar .objs misto na mesma compilação, a capacidade de verificação do arquivo de saída resultante, por padrão, será igual ao menor nível de capacidade de verificação dos módulos de entrada. 
  
 Se você possui um aplicativo que é composto de dois ou mais assemblies e você deseja que o aplicativo a ser contido em um assembly, você deve recompilar os assemblies e vincule o .objs ou. netmodules para produzir um único assembly.  
  
 Você deve especificar um ponto de entrada usando [/ENTRY (símbolo de ponto de entrada)](../../build/reference/entry-entry-point-symbol.md) ao criar uma imagem executável.  
  
 Ao vincular com um arquivo. obj ou. netmodule do MSIL, use [/LTCG (geração de código Link-time)](../../build/reference/ltcg-link-time-code-generation.md), caso contrário, quando o vinculador encontra o MSIL obj ou. netmodule, ele reiniciará o link com /LTCG.  
  
 Arquivos. obj ou. netmodule MSIL também podem ser passados para cl.exe.  
  
 Arquivos de. obj ou. netmodule MSIL entrada não podem ter recursos inseridos. Um recurso é inserido em um arquivo de saída (módulo ou assembly) com [/ASSEMBLYRESOURCE. (incorporar um recurso gerenciado)](../../build/reference/assemblyresource-embed-a-managed-resource.md) opção de vinculador ou com o **/resource** opção de compilador em outros compiladores do Visual Studio.  
  
 Ao executar a vinculação MSIL e se você não especificar também [/LTCG (geração de código Link-time)](../../build/reference/ltcg-link-time-code-generation.md), você verá uma mensagem informativa relatar que o link está reiniciando. Essa mensagem pode ser ignorada, mas to melhorar performance do vinculador com vinculação MSIL, especificar explicitamente **/LTCG**.  
  
## <a name="example"></a>Exemplo  
 No código C++ do bloco catch de um bloco try correspondente será invocado para uma exceção não são do sistema. No entanto, por padrão, o CLR ajusta exceções não são do sistema com <xref:System.Runtime.CompilerServices.RuntimeWrappedException>. Quando um assembly é criado a partir do Visual C++ e módulos não Visual C++ e você desejar que um bloco catch no código C++ a ser invocada em sua cláusula try correspondente quando o bloco try gera uma exceção não são do sistema, você deve adicionar o  
  
 atributo [assembly:System::Runtime::CompilerServices::RuntimeCompatibility(WrapNonExceptionThrows=false)] para o código-fonte para os módulos não C++.  
  
```  
// MSIL_linking.cpp  
// compile with: /c /clr  
value struct V {};  
  
ref struct MCPP {  
   static void Test() {  
      try {  
         throw (gcnew V);  
      }  
      catch (V ^) {  
         System::Console::WriteLine("caught non System exception in C++ source code file");  
      }  
   }  
};  
  
/*  
int main() {  
   MCPP::Test();  
}  
*/  
```  
  
## <a name="example"></a>Exemplo  
 Alterando o valor booliano do atributo WrapNonExceptionThrows, você deve modificar a capacidade do código do Visual C++ para capturar uma exceção não são do sistema.  
  
```  
// MSIL_linking_2.cs  
// compile with: /target:module /addmodule:MSIL_linking.obj  
// post-build command: link /LTCG MSIL_linking.obj MSIL_linking_2.netmodule /entry:MLinkTest.Main /out:MSIL_linking_2.exe /subsystem:console  
using System.Runtime.CompilerServices;  
  
// enable non System exceptions  
[assembly:RuntimeCompatibility(WrapNonExceptionThrows=false)]  
  
class MLinkTest {  
   public static void Main() {  
      try {  
         MCPP.Test();  
      }  
      catch (RuntimeWrappedException) {  
         System.Console.WriteLine("caught a wrapped exception in C#");  
      }  
   }  
}  
```  
  
```Output  
caught non System exception in C++ source code file  
```  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos de entrada de LINK](../../build/reference/link-input-files.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)