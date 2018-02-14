---
title: 'Como: migrar para o clr-: puro (C + + CLI) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- /clr compiler option [C++], migrating to /clr:pure
- migration [C++], pure MSIL
- pure MSIL [C++], porting to
ms.assetid: 5ffb1184-2095-4ade-84aa-4fa6324bc764
caps.latest.revision: "15"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: b8d49ee233167c02570408ba091c2a99b78487d5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-migrate-to-clrpure-ccli"></a>Como migrar para /clr:pure (C++/CLI)
Este tópico discute problemas surgirão ao migrar para o uso de MSIL puro **/clr: pure** (consulte [/clr (Common Language Runtime Compilation)](../build/reference/clr-common-language-runtime-compilation.md) para obter mais informações). Este tópico pressupõe que o código que está sendo migrado no momento é compilado como assembly misto usando o **/clr** opção, pois o caminho de migração de código não gerenciado para MSIL puro não é um direto. Para código não gerenciado, consulte [como: migrar para /clr](../dotnet/how-to-migrate-to-clr.md) antes de tentar migrar para o MSIL puro.  
  
## <a name="basic-changes"></a>Alterações básicas  
 MSIL puro é composto de instruções da MSIL, portanto o código que contém funções que não podem ser expressa em MSIL impedirá a compilação. Isso inclui funções definidas como usando convenções de chamada que [clrcall](../cpp/clrcall.md). (Funções de clrcall não podem ser invocadas em um componente MSIL puro, mas não definidas.)  
  
 Para não garantir que nenhum erro de tempo de execução, você deve habilitar o aviso C4412. Habilitar C4412 adicionando `#pragma warning (default : 4412)` para cada compiland que você compile com **/clr: pure** e passa os tipos de C++ de e para IJW (**/clr)** ou código nativo. Consulte [C4412 de aviso do compilador (nível 2)](../error-messages/compiler-warnings/compiler-warning-level-2-c4412.md) para obter mais informações.  
  
## <a name="architectural-considerations"></a>Considerações de arquitetura  
 Algumas das limitações de assemblies MSIL puros listados na [puro e código verificável (C + + CLI)](../dotnet/pure-and-verifiable-code-cpp-cli.md) ter implicações de alto nível para a estratégia de design e a migração de aplicativos. Notadamente, ao contrário de assemblies mistos, assemblies MSIL puros não desfrutam compatibilidade total com módulos não gerenciados.  
  
 Assemblies MSIL puros podem chamar funções não gerenciadas, mas não podem ser chamados por funções não gerenciadas. Como resultado, MSIL puro é um candidato melhor para o código de cliente que usa funções não gerenciadas que para o código de servidor que é usado por funções não gerenciadas. Se a funcionalidade contida em um assembly MSIL puro está para ser usado por funções não gerenciadas, um conjunto misto deve ser usado como uma camada de interface.  
  
 Aplicativos que usam ATL ou MFC não são bons candidatos à migração para MSIL puro, pois essas bibliotecas não têm suporte nesta versão. Da mesma forma, o [!INCLUDE[winsdkshort](../atl-mfc-shared/reference/includes/winsdkshort_md.md)] contém arquivos de cabeçalho não compilam em **/clr: pure**.  
  
 Embora assemblies MSIL puros podem chamar funções não gerenciadas, essa capacidade é limitada às funções de estilo C simples. O uso de APIs não gerenciadas mais complexo é provavelmente exigirá a funcionalidade não gerenciada a ser exposto na forma de uma interface COM, ou um conjunto misto que pode agir como uma interface entre o MSIL puro e componentes não gerenciados. Usando uma conjunto misto camada é a única maneira de usar funções não gerenciadas que usam funções de retorno de chamada, por exemplo, como um assembly puro é capaz de fornecer uma função de chamada nativa para uso como um retorno de chamada.  
  
## <a name="application-domains-and-calling-conventions"></a>Domínios do aplicativo e convenções de chamada  
 Embora seja possível para MSIL puro assemblies usam recursos não gerenciados, funções e dados estáticos são tratados de maneira diferente. Assemblies puros, as funções são implementadas com o [clrcall](../cpp/clrcall.md) chamando convenção e dados estáticos é armazenado domínio de aplicativo. Isso é diferente do padrão para assemblies gerenciados e mistos, que usam o [cdecl](../cpp/cdecl.md) convenção de chamada para funções e armazenar dados estáticos em uma base por processo.  
  
 Dentro do contexto de MSIL puro (e verificável código compilado com /CLR: Safe) esses padrões são transparentes, como [clrcall](../cpp/clrcall.md) é a convenção de chamada padrão do CLR e domínios de aplicativo são o escopo nativo para estático e dados globais em aplicativos .NET. No entanto, quando uma interface com componentes não gerenciados ou mistos, o tratamento diferente de dados globais e funções pode causar problemas.  
  
 Por exemplo, se for um componente MSIL puro chamar funções em uma DLL não gerenciada ou mista, um arquivo de cabeçalho para a DLL será usado para compilar o assembly puro. No entanto, a menos que a convenção de chamada para cada função no cabeçalho é especificada explicitamente, eles serão todos considerados [clrcall](../cpp/clrcall.md). Isso mais tarde causará falhas de tempo de execução, como essas funções são provavelmente implementado com o [cdecl](../cpp/cdecl.md) convenção. As funções no arquivo de cabeçalho não gerenciados podem ser explicitamente marcadas como [cdecl](../cpp/cdecl.md), ou todo o código de origem do DLL deve ser recompilado em **/clr: pure**.  
  
 Da mesma forma, os ponteiros de função são considerados para apontar para [clrcall](../cpp/clrcall.md) funciona em **/clr: pure** compilação. Eles também devem ser explicitamente anotados com a convenção de chamada correta.  
  
 Para obter mais informações, consulte [domínios do aplicativo e do Visual C++](../dotnet/application-domains-and-visual-cpp.md).  
  
## <a name="linking-limitations"></a>Limitações de vinculação  
 O vinculador do Visual C++ não tentará vincular arquivos OBJ mistos e puros, conforme as convenções de escopo e chamada de armazenamento são diferentes.  
  
## <a name="see-also"></a>Consulte também  
 [Código puro e verificável (C++/CLI)](../dotnet/pure-and-verifiable-code-cpp-cli.md)