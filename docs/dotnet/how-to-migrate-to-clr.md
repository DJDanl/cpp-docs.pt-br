---
title: Como migrar para -clr
ms.custom: get-started-article
ms.date: 09/18/2018
helpviewer_keywords:
- upgrading Visual C++ applications, /clr compiler option
- compiling native code [C++]
- interoperability [C++], /clr compiler option
- interop [C++], /clr compiler option
- migration [C++], /clr compiler option
- /clr compiler option [C++], porting to
ms.assetid: c9290b8b-436a-4510-8b56-eae51f4a9afc
ms.openlocfilehash: 339b1f3172d8b82ece3e98f117f53ed399cbd4e2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376074"
---
# <a name="how-to-migrate-to-clr"></a>Como migrar para /clr

Este tópico discute questões que surgem ao compilar código nativo com **/clr** (ver [/clr (Common Language Runtime Compilation)](../build/reference/clr-common-language-runtime-compilation.md) para obter mais informações). **/clr** permite que o código C++ nativo invoque e seja invocado a partir de conjuntos .NET, além de outros códigos C++ nativos. Consulte [Conjuntos Mistos (Nativos e Gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md) e [Interoperabilidade Nativa e .NET](../dotnet/native-and-dotnet-interoperability.md) para obter mais informações sobre as vantagens de compilar com **/clr**.

## <a name="known-issues-compiling-library-projects-with-clr"></a>Problemas conhecidos compilando projetos de biblioteca com /clr

O Visual Studio contém alguns problemas conhecidos ao compilar projetos de biblioteca com **/clr**:

- Seu código pode consultar tipos em tempo de execução com [CRuntimeClass::FromName](../mfc/reference/cruntimeclass-structure.md#fromname). No entanto, se um tipo estiver em um MSIL .dll `FromName` (compilado com **/clr),** a chamada pode falhar se ocorrer antes que os construtores estáticos sejam executados no .dll gerenciado (você não verá esse problema se a chamada FromName acontecer após o código ter sido executado no .dll gerenciado). Para contornar esse problema, você pode forçar a construção do construtor estático gerenciado definindo uma função no .dll gerenciado, exportando-o e invocando-o a partir da aplicação MFC nativa. Por exemplo:

    ```
    // MFC extension DLL Header file:
    __declspec( dllexport ) void EnsureManagedInitialization () {
       // managed code that won't be optimized away
       System::GC::KeepAlive(System::Int32::MaxValue);
    }
    ```

## <a name="compile-with-visual-c"></a>Compilar com Visual C++

Antes de usar **/clr** em qualquer módulo do seu projeto, primeiro compile e conecte seu projeto nativo com o Visual Studio 2010.

As etapas a seguir, seguidas em ordem, fornecem o caminho mais fácil para uma compilação **/clr.** É importante compilar e executar seu projeto após cada uma dessas etapas.

### <a name="versions-prior-to-visual-studio-2003"></a>Versões anteriores ao Visual Studio 2003

Se você estiver atualizando para o Visual Studio 2010 de uma versão anterior ao Visual Studio 2003, você pode ver erros de compilador relacionados à conformidade padrão C++ aprimorada no Visual Studio 2003

### <a name="upgrading-from-visual-studio-2003"></a>Atualização do Visual Studio 2003

Projetos anteriormente construídos com o Visual Studio 2003 também devem ser compilados sem **/clr,** já que o Visual Studio agora aumentou a conformidade ANSI/ISO e algumas mudanças de quebra. A mudança que provavelmente exigirá mais atenção são [os Recursos de Segurança no CRT](../c-runtime-library/security-features-in-the-crt.md). O código que usa o CRT é muito provável que produza avisos de depreciação. Esses avisos podem ser suprimidos, mas a migração para as novas [versões aprimoradas de segurança das funções CRT](../c-runtime-library/security-enhanced-versions-of-crt-functions.md) é preferível, pois fornecem melhor segurança e podem revelar problemas de segurança em seu código.

### <a name="upgrading-from-managed-extensions-for-c"></a>Atualização de extensões gerenciadas para C++

A partir do Visual Studio 2005, o código escrito com extensões gerenciadas para C++ não será compilado em **/clr**.

## <a name="convert-c-code-to-c"></a>Converter código C para C++

Embora o Visual Studio compile arquivos C, é necessário convertê-los em C++ para uma compilação **/clr.** O nome de arquivo real não precisa ser alterado; você pode usar **/Tp** (ver [/Tc, /Tp, /TC, /TP (Especificar tipo de arquivo de origem)](../build/reference/tc-tp-tc-tp-specify-source-file-type.md).) Observe que, embora os arquivos de código fonte C++ sejam necessários para **/clr,** não é necessário refatorar seu código para usar paradigmas orientados a objetos.

É muito provável que o código C exija alterações quando compilado como um arquivo C++. As regras de segurança do tipo C++ são rígidas, por isso as conversões de tipo devem ser explicitadas com moldes. Por exemplo, malloc retorna um ponteiro vazio, mas pode ser atribuído a um ponteiro para qualquer tipo em C com um elenco:

```
int* a = malloc(sizeof(int));   // C code
int* b = (int*)malloc(sizeof(int));   // C++ equivalent
```

Os ponteiros de função também são estritamente seguros para o tipo em C++, de modo que o seguinte código C requer modificação. Em C++ é melhor criar `typedef` um que defina o tipo de ponteiro de função e, em seguida, use esse tipo para lançar ponteiros de função:

```
NewFunc1 = GetProcAddress( hLib, "Func1" );   // C code
typedef int(*MYPROC)(int);   // C++ equivalent
NewFunc2 = (MYPROC)GetProcAddress( hLib, "Func2" );
```

C++ também exige que as funções sejam protótipos ou totalmente definidas antes de serem referenciadas ou invocadas.

Os identificadores usados no código C que por acaso são palavras-chave em C++ (como **virtual,** **novo,** **exclusão,** **bool,** **true,** **false,** etc.) devem ser renomeados. Isso geralmente pode ser feito com operações simples de busca e substituição.

```
COMObj1->lpVtbl->Method(COMObj, args);  // C code
COMObj2->Method(args);  // C++ equivalent
```

## <a name="reconfigure-project-settings"></a>Reconfigurar configurações do projeto

Depois que seu projeto for compilado e executado no Visual Studio 2010, você deve criar novas configurações de projeto para **/clr** em vez de modificar as configurações padrão. **/clr** é incompatível com algumas opções de compilador e criar configurações separadas permite que você construa seu projeto como nativo ou gerenciado. Quando **/clr** é selecionado na caixa de diálogo páginas de propriedade, as configurações do projeto não compatíveis com **/clr** são desativadas (e as opções desativadas não são restauradas automaticamente se **/clr** for posteriormente não selecionado).

### <a name="create-new-project-configurations"></a>Criar novas configurações de projeto

Você pode usar **configurações de cópia a partir da** opção na caixa de diálogo de **configuração de configuração** de novo projeto **(Build** > **Configuration Manager** > **Active Solution Configuration** > **New)** para criar uma configuração de projeto baseada nas configurações de projeto existentes. Faça isso uma vez na configuração Debug e uma vez para a configuração Derelease. Alterações subseqüentes podem ser aplicadas apenas às configurações **específicas /clr,** deixando intactas as configurações originais do projeto.

Projetos que usam regras de construção personalizadas podem exigir atenção extra.

Esta etapa tem diferentes implicações para projetos que usam makefiles. Neste caso, um build-target separado pode ser configurado, ou a versão específica para **compilação /clr** pode ser criada a partir de uma cópia do original.

### <a name="change-project-settings"></a>Alterar configurações do projeto

**/clr** pode ser selecionado no ambiente de desenvolvimento seguindo as instruções em [/clr (Common Language Runtime Compilation)](../build/reference/clr-common-language-runtime-compilation.md). Como mencionado anteriormente, esta etapa desativará automaticamente as configurações conflitantes do projeto.

> [!NOTE]
> Ao atualizar uma biblioteca gerenciada ou um projeto de serviço web do Visual Studio 2003, a opção **compilador /Zl** será adicionada à página de propriedade **'Linha de Comando'.** Isso causará lNK2001. Remover **/Zl** da página de propriedade Linha de **Comando** para resolver. Consulte [/Zl (Omit Default Library Name)](../build/reference/zl-omit-default-library-name.md) e [Defina propriedades e construa propriedades](../build/working-with-project-properties.md) para obter mais informações. Ou, adicione msvcrt.lib e msvcmrt.lib à propriedade **Dependências Adicionais** do linker.

Para projetos construídos com makefiles, as opções de compilador incompatíveis devem ser desativadas manualmente uma vez **que /clr** seja adicionado. Consulte /[/clr Restrições](../build/reference/clr-restrictions.md) para obter informações sobre opções de compilador que não sejam compatíveis com **/clr**.

### <a name="precompiled-headers"></a>Cabeçalhos Pré-compilados

Os cabeçalhos pré-compilados são suportados em **/clr**. No entanto, se você apenas compilar alguns de seus arquivos CPP com **/clr** (compilando o resto como nativo), algumas alterações serão necessárias porque os cabeçalhos pré-compilados gerados com **/clr** não são compatíveis com aqueles gerados sem **/clr**. Essa incompatibilidade se deve ao fato de que **/clr** gera e requer metadados. Os módulos compilados **/clr** não podem, portanto, usar cabeçalhos pré-compilados que não incluam metadados, e os módulos **não/clr** não podem usar arquivos de cabeçalho pré-compilados que contenham metadados.

A maneira mais fácil de compilar um projeto onde alguns módulos são compilados **/clr** é desativar totalmente os cabeçalhos pré-compilados. (Na caixa de diálogo Páginas de propriedade do projeto, abra o nó C/C++ e selecione Cabeçalhos pré-compilados. Em seguida, altere a propriedade 'Criar/Usar cabeçalhos precompilados' para "Não usar cabeçalhos pré-compilados".)

No entanto, particularmente para grandes projetos, os cabeçalhos pré-compilados fornecem uma velocidade de compilação muito melhor, portanto, desativar esse recurso não é desejável. Neste caso, é melhor configurar os arquivos **/clr** e **non/clr** para usar cabeçalhos pré-compilados separados. Isso pode ser feito em uma etapa, selecionando vários módulos a serem compilados **/clr** usando **o Solution Explorer,** clicando com o botão direito do mouse no grupo e selecionando Propriedades. Em seguida, altere as propriedades Criar/Usar PCH através de arquivo e arquivo de cabeçalho pré-compilado para usar um nome de arquivo de cabeçalho diferente e arquivo PCH, respectivamente.

## <a name="fixing-errors"></a>Corrigindo erros

A compilação com **/clr** pode resultar em erros de compilador, linker ou runtime. Esta seção discute os problemas mais comuns.

### <a name="metadata-merge"></a>Mesclagem de metadados

Versões diferentes de tipos de dados podem fazer com que o linker falhe porque os metadados gerados para os dois tipos não correspondem. (Isso geralmente é causado quando membros de um tipo são condicionados definidos, mas as condições não são as mesmas para todos os arquivos CPP que usam o tipo.) Neste caso, o linker falha, relatando apenas o nome do símbolo e o nome do segundo arquivo OBJ onde o tipo foi definido. Muitas vezes é útil girar a ordem que os arquivos OBJ são enviados para o linker para descobrir a localização da outra versão do tipo de dados.

### <a name="loader-lock-deadlock"></a>Impasse de bloqueio do carregador

O "impasse de bloqueio do carregador" pode ocorrer, mas é determinístico e é detectado e relatado em tempo de execução. Consulte [Inicialização de Conjuntos Mistos](../dotnet/initialization-of-mixed-assemblies.md) para obter informações detalhadas sobre o fundo, orientação e soluções.

### <a name="data-exports"></a>Exportações de Dados

Exportar dados DLL é propenso a erros e não é recomendado. Isso porque a seção de dados de uma DLL não é garantida para ser inicializada até que alguma parte gerenciada da DLL tenha sido executada. Referência de metadados com [diretiva #using](../preprocessor/hash-using-directive-cpp.md).

### <a name="type-visibility"></a>Visibilidade de tipo

Os tipos nativos são privados por padrão. Isso pode resultar em um tipo nativo não ser visível fora da DLL. Resolva este `public` erro adicionando a esses tipos.

### <a name="floating-point-and-alignment-issues"></a>Problemas de ponto flutuante e alinhamento

`__controlfp`não é suportado no tempo de execução do idioma comum (ver [_control87, _controlfp, \__control87_2](../c-runtime-library/reference/control87-controlfp-control87-2.md) para obter mais informações). A CLR também não respeitará [o alinhamento](../cpp/align-cpp.md).

### <a name="com-initialization"></a>Inicialização COM

O Common Language Runtime inicializa o COM automaticamente quando um módulo é inicializado (quando o COM é inicializado automaticamente, ele é feito como MTA). Como resultado, a inicialização explícita do COM produz códigos de retorno indicando que o COM já está inicializado. Tentar inicializar explicitamente o COM com um modelo de threading quando a CLR já inicializou o COM para outro modelo de threading pode fazer com que seu aplicativo falhe.

O tempo de execução do idioma comum inicia o COM como MTA por padrão; use [/CLRTHREADATTRIBUTE (Set CLR Thread Attribute)](../build/reference/clrthreadattribute-set-clr-thread-attribute.md) para modificá-lo.

### <a name="performance-issues"></a>Problemas de desempenho

Você pode ver o desempenho reduzido quando os métodos C++ nativos gerados ao MSIL são chamados indiretamente (chamadas de função virtual ou usando ponteiros de função). Para saber mais sobre isso, consulte [Double Thunking](../dotnet/double-thunking-cpp.md).

Ao mudar de nativo para MSIL, você notará um aumento no tamanho do seu conjunto de trabalho. Isso porque o tempo de execução do idioma comum fornece muitos recursos para garantir que os programas são executados corretamente. Se o aplicativo **/clr** não estiver funcionando corretamente, você pode querer ativar C4793 (desligado por padrão), consulte [Aviso do Compilador (nível 1 e 3) C4793](../error-messages/compiler-warnings/compiler-warning-level-1-and-3-c4793.md) para obter mais informações.

### <a name="program-crashes-on-shutdown"></a>Programa trava no desligamento

Em alguns casos, o CLR pode desligar antes que seu código gerenciado seja concluído. Usar `std::set_terminate` `SIGTERM` e pode causar isso. Consulte [as constantes de sinal](../c-runtime-library/signal-constants.md) e [set_terminate](../c-runtime-library/abnormal-termination.md) para obter mais informações.

## <a name="using-new-visual-c-features"></a>Usando novos recursos visuais C++

Depois que seu aplicativo compila, vincula e executa, você pode começar a usar recursos .NET em qualquer módulo compilado com **/clr**. Para obter mais informações, consulte [Extensões de componentes para plataformas de runtime](../extensions/component-extensions-for-runtime-platforms.md).

Para obter informações sobre a programação .NET no Visual C++ consulte:

- [.NET Programação com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)

- [Nativo e interoperabilidade .NET](../dotnet/native-and-dotnet-interoperability.md)

- [Extensões de componentes para plataformas de runtime](../extensions/component-extensions-for-runtime-platforms.md)

## <a name="see-also"></a>Confira também

[Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md)
