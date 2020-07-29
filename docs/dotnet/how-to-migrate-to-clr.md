---
title: 'Como: migrar para o -clr'
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
ms.openlocfilehash: 0c21fe585049ebce6383c5d8f673704e7362cd72
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225690"
---
# <a name="how-to-migrate-to-clr"></a>Como migrar para /clr

Este tópico discute os problemas que surgem durante a compilação de código nativo com **/CLR** (consulte [/CLR (compilação do Common Language Runtime)](../build/reference/clr-common-language-runtime-compilation.md) para obter mais informações). o **/CLR** permite que o código c++ nativo invoque e seja invocado a partir de assemblies do .net, além de outro código c++ nativo. Consulte [assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md) e a [interoperabilidade nativa e .net](../dotnet/native-and-dotnet-interoperability.md) para obter mais informações sobre as vantagens da compilação com o **/CLR**.

## <a name="known-issues-compiling-library-projects-with-clr"></a>Problemas conhecidos ao compilar projetos de biblioteca com/CLR

O Visual Studio contém alguns problemas conhecidos ao compilar projetos de biblioteca com **/CLR**:

- Seu código pode consultar tipos em tempo de execução com [CRuntimeClass:: FromName](../mfc/reference/cruntimeclass-structure.md#fromname). No entanto, se um tipo estiver em um MSIL. dll (compilado com **/CLR**), a chamada para `FromName` poderá falhar se ocorrer antes que os construtores estáticos sejam executados no Managed. dll (você não verá esse problema se a chamada FromName ocorrer depois que o código for executado no Managed. dll). Para contornar esse problema, você pode forçar a construção do construtor estático gerenciado definindo uma função no Managed. dll, exportando-o e invocando-o do aplicativo MFC nativo. Por exemplo:

    ```
    // MFC extension DLL Header file:
    __declspec( dllexport ) void EnsureManagedInitialization () {
       // managed code that won't be optimized away
       System::GC::KeepAlive(System::Int32::MaxValue);
    }
    ```

## <a name="compile-with-visual-c"></a>Compilar com Visual C++

Antes de usar o **/CLR** em qualquer módulo em seu projeto, primeiro compile e vincule seu projeto nativo com o Visual Studio 2010.

As etapas a seguir, seguidas em ordem, fornecem o caminho mais fácil para uma compilação **/CLR** . É importante compilar e executar o projeto após cada uma dessas etapas.

### <a name="versions-prior-to-visual-studio-2003"></a>Versões anteriores ao Visual Studio 2003

Se você estiver atualizando para o Visual Studio 2010 de uma versão anterior ao Visual Studio 2003, você poderá ver erros do compilador relacionados à conformidade padrão do C++ aprimorado no Visual Studio 2003

### <a name="upgrading-from-visual-studio-2003"></a>Atualizando do Visual Studio 2003

Projetos criados anteriormente com o Visual Studio 2003 também devem ser compilados primeiro sem o **/CLR** , já que o Visual Studio agora aumentou a conformidade com ANSI/ISO e algumas alterações significativas. A alteração que provavelmente exigirá mais atenção é os [recursos de segurança no CRT](../c-runtime-library/security-features-in-the-crt.md). O código que usa o CRT é muito provável para produzir avisos de substituição. Esses avisos podem ser suprimidos, mas a migração para as novas [versões avançadas de segurança das funções do CRT](../c-runtime-library/security-enhanced-versions-of-crt-functions.md) é preferida, pois elas fornecem melhor segurança e podem revelar problemas de segurança em seu código.

### <a name="upgrading-from-managed-extensions-for-c"></a>Atualizando do Managed Extensions for C++

A partir do Visual Studio 2005, o código escrito com Managed Extensions for C++ não será compilado em **/CLR**.

## <a name="convert-c-code-to-c"></a>Converter código C em C++

Embora o Visual Studio compile os arquivos C, é necessário convertê-los em C++ para uma compilação **/CLR** . O nome de arquivo real não precisa ser alterado; Você pode usar **/TP** (consulte [/TC,/TP,/TC,/TP (especifique o tipo de arquivo de origem)](../build/reference/tc-tp-tc-tp-specify-source-file-type.md).) Observe que, embora os arquivos de código-fonte do C++ sejam necessários para o **/CLR**, não é necessário refatorar seu código para usar paradigmas orientados a objeto.

É muito provável que o código C exija alterações quando compilado como um arquivo C++. As regras de segurança de tipo C++ são estritas, portanto, conversões de tipo devem ser feitas explícitas com conversões. Por exemplo, malloc retorna um ponteiro void, mas pode ser atribuído a um ponteiro para qualquer tipo em C com uma conversão:

```
int* a = malloc(sizeof(int));   // C code
int* b = (int*)malloc(sizeof(int));   // C++ equivalent
```

Os ponteiros de função também são estritamente fortemente tipados em C++, portanto, o código C a seguir requer modificação. Em C++, é melhor criar um **`typedef`** que defina o tipo de ponteiro de função e, em seguida, usar esse tipo para converter ponteiros de função:

```
NewFunc1 = GetProcAddress( hLib, "Func1" );   // C code
typedef int(*MYPROC)(int);   // C++ equivalent
NewFunc2 = (MYPROC)GetProcAddress( hLib, "Func2" );
```

O C++ também exige que as funções sejam modeladas ou totalmente definidas antes que possam ser referenciadas ou invocadas.

Os identificadores usados no código C que são palavras-chave em C++ (como,,,, **`virtual`** **`new`** **`delete`** **`bool`** **`true`** , **`false`** etc.) devem ser renomeados. Isso geralmente pode ser feito com operações simples de pesquisa e substituição.

```
COMObj1->lpVtbl->Method(COMObj, args);  // C code
COMObj2->Method(args);  // C++ equivalent
```

## <a name="reconfigure-project-settings"></a>Reconfigurar configurações do projeto

Depois que o projeto for compilado e executado no Visual Studio 2010, você deverá criar novas configurações de projeto para **/CLR** em vez de modificar as configurações padrão. o **/CLR** é incompatível com algumas opções de compilador e a criação de configurações separadas permite que você crie seu projeto como nativo ou gerenciado. Quando **/CLR** é selecionado na caixa de diálogo páginas de propriedades, as configurações do projeto não são compatíveis com o **/CLR** são desabilitadas (e as opções desabilitadas não são restauradas automaticamente se **/CLR** estiver subsequentemente desmarcada).

### <a name="create-new-project-configurations"></a>Criar novas configurações de projeto

Você pode usar a opção **copiar configurações de** na **caixa de diálogo Nova configuração de projeto** (**Compilar**  >  **Configuration Manager**  >  **configuração de solução ativa**  >  **nova**) para criar uma configuração de projeto com base nas configurações de projeto existentes. Faça isso uma vez para a configuração de depuração e uma vez para a configuração de versão. As alterações subsequentes podem ser aplicadas somente às configurações de **/CLR** específicas, deixando as configurações do projeto original intactas.

Os projetos que usam regras de compilação personalizadas podem exigir atenção extra.

Esta etapa tem diferentes implicações para projetos que usam makefiles. Nesse caso, um destino de compilação separado pode ser configurado, ou a versão específica para compilação **/CLR** pode ser criada a partir de uma cópia do original.

### <a name="change-project-settings"></a>Alterar configurações do projeto

o **/CLR** pode ser selecionado no ambiente de desenvolvimento seguindo as instruções em [/CLR (compilação em tempo de execução de linguagem comum)](../build/reference/clr-common-language-runtime-compilation.md). Conforme mencionado anteriormente, essa etapa desabilitará automaticamente as configurações de projeto conflitantes.

> [!NOTE]
> Ao atualizar uma biblioteca gerenciada ou um projeto de serviço Web do Visual Studio 2003, a opção de compilador **/zl** será adicionada à página de propriedades de **linha de comando** . Isso causará LNK2001. Remova **/zl** da página de propriedades de **linha de comando** para resolver. Consulte [/zl (omitir nome de biblioteca padrão)](../build/reference/zl-omit-default-library-name.md) e [definir compilador e propriedades de compilação](../build/working-with-project-properties.md) para obter mais informações. Ou adicione msvcrt. lib e msvcmrt. lib à propriedade **dependências adicionais** do vinculador.

Para projetos criados com makefiles, as opções de compilador incompatíveis devem ser desabilitadas manualmente após a adição de **/CLR** . Consulte[restrições/CLR](../build/reference/clr-restrictions.md) para obter informações sobre as opções do compilador que não são compatíveis com o **/CLR**.

### <a name="precompiled-headers"></a>Cabeçalhos Pré-compilados

Cabeçalhos pré-compilados têm suporte em **/CLR**. No entanto, se você compilar apenas alguns dos seus arquivos CPP com **/CLR** (compilando o REST como nativo), algumas alterações serão necessárias porque os cabeçalhos pré-compilados gerados com **/CLR** não são compatíveis com aqueles gerados sem **/CLR**. Essa incompatibilidade ocorre devido ao fato de o **/CLR** gerar e exigir metadados. Módulos compilados **/CLR** , portanto, não usam cabeçalhos pré-compilados que não incluem metadados, e módulos não- **/CLR** não podem usar arquivos de cabeçalho pré-compilados que contêm metadados.

A maneira mais fácil de compilar um projeto em que alguns módulos são compilados com **/CLR** é desabilitar totalmente os cabeçalhos pré-compilados. (Na caixa de diálogo páginas de propriedades do projeto, abra o nó C/C++ e selecione cabeçalhos pré-compilados. Em seguida, altere a propriedade criar/usar cabeçalhos pré-compilados para "não usar cabeçalhos pré-compilados".)

No entanto, particularmente para projetos grandes, os cabeçalhos pré-compilados fornecem uma velocidade de compilação muito melhor, portanto, desabilitar esse recurso não é desejável. Nesse caso, é melhor configurar os arquivos **/CLR** e não **/CLR** para usar cabeçalhos pré-compilados separados. Isso pode ser feito em uma etapa, selecionando vários módulos para serem compilados com **/CLR** usando **Gerenciador de soluções**, clicando com o botão direito do mouse no grupo e selecionando Propriedades. Em seguida, altere as propriedades criar/usar PCH por arquivo e cabeçalho pré-compilado para usar um nome de arquivo de cabeçalho diferente e um arquivo PCH, respectivamente.

## <a name="fixing-errors"></a>Corrigindo erros

A compilação com **/CLR** pode resultar em erros de compilador, de vinculador ou de tempo de execução. Esta seção aborda os problemas mais comuns.

### <a name="metadata-merge"></a>Mesclagem de metadados

Diferentes versões de tipos de dados podem causar falha no vinculador porque os metadados gerados para os dois tipos não correspondem. (Isso geralmente ocorre quando os membros de um tipo são definidos condicionalmente, mas as condições não são as mesmas para todos os arquivos CPP que usam o tipo.) Nesse caso, o vinculador falha, relatando apenas o nome do símbolo e o nome do segundo arquivo OBJ em que o tipo foi definido. Geralmente, é útil girar a ordem em que os arquivos OBJ são enviados ao vinculador para descobrir o local da outra versão do tipo de dados.

### <a name="loader-lock-deadlock"></a>Deadlock de bloqueio de carregador

O "deadlock de bloqueio do carregador" pode ocorrer, mas é determinístico e é detectado e relatado em tempo de execução. Consulte [inicialização de assemblies mistos](../dotnet/initialization-of-mixed-assemblies.md) para obter informações detalhadas, orientações e soluções.

### <a name="data-exports"></a>Exportações de dados

Exportar dados DLL é propenso a erros e não é recomendado. Isso ocorre porque a seção de dados de uma DLL não tem garantia de ser inicializada até que uma parte gerenciada da DLL tenha sido executada. Metadados de referência com a [diretiva #using](../preprocessor/hash-using-directive-cpp.md).

### <a name="type-visibility"></a>Visibilidade de tipo

Os tipos nativos são privados por padrão. Isso pode resultar em um tipo nativo não estar visível fora da DLL. Resolva esse erro adicionando **`public`** a esses tipos.

### <a name="floating-point-and-alignment-issues"></a>Problemas de ponto e alinhamento flutuantes

`__controlfp`Não tem suporte no Common Language Runtime (consulte [_control87, _controlfp \_ _control87_2](../c-runtime-library/reference/control87-controlfp-control87-2.md) para obter mais informações). O CLR também não respeitará o [alinhamento](../cpp/align-cpp.md).

### <a name="com-initialization"></a>Inicialização COM

O Common Language Runtime Inicializa COM automaticamente quando um módulo é inicializado (quando COM é inicializado automaticamente, ele é feito de modo que o MTA). Como resultado, a inicialização explícita de COM gera códigos de retorno indicando que o COM já foi inicializado. Tentar inicializar explicitamente com com um modelo de Threading quando o CLR já tiver inicializado com outro modelo de Threading pode causar falha no aplicativo.

O Common Language Runtime inicia COM como MTA por padrão; Use [/CLRTHREADATTRIBUTE (definir atributo de thread CLR)](../build/reference/clrthreadattribute-set-clr-thread-attribute.md) para modificar isso.

### <a name="performance-issues"></a>Problemas de desempenho

Você pode ver o desempenho reduzido quando métodos C++ nativos gerados para MSIL são chamados indiretamente (chamadas de função virtual ou usando ponteiros de função). Para saber mais sobre isso, confira [conversão dupla](../dotnet/double-thunking-cpp.md).

Ao mudar do nativo para o MSIL, você observará um aumento no tamanho do seu conjunto de trabalho. Isso ocorre porque o Common Language Runtime fornece muitos recursos para garantir que os programas sejam executados corretamente. Se seu aplicativo **/CLR** não estiver sendo executado corretamente, talvez você queira habilitar C4793 (desativado por padrão), consulte [aviso do compilador (nível 1 e 3) C4793](../error-messages/compiler-warnings/compiler-warning-level-1-and-3-c4793.md) para obter mais informações.

### <a name="program-crashes-on-shutdown"></a>O programa falha durante o desligamento

Em alguns casos, o CLR pode ser desligado antes da conclusão da execução do código gerenciado. Usar `std::set_terminate` e `SIGTERM` pode causar isso. Consulte as [constantes de sinal](../c-runtime-library/signal-constants.md) e [set_terminate](../c-runtime-library/abnormal-termination.md) para obter mais informações.

## <a name="using-new-visual-c-features"></a>Usando novos recursos de Visual C++

Depois que o aplicativo for compilado, vinculado e executado, você poderá começar a usar os recursos do .NET em qualquer módulo compilado com **/CLR**. Para obter mais informações, consulte [Extensões de componentes para plataformas de runtime](../extensions/component-extensions-for-runtime-platforms.md).

Para obter informações sobre a programação do .NET no Visual C++ consulte:

- [Programação .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)

- [Interoperabilidade entre nativo e .NET](../dotnet/native-and-dotnet-interoperability.md)

- [Extensões de componentes para plataformas de runtime](../extensions/component-extensions-for-runtime-platforms.md)

## <a name="see-also"></a>Confira também

[Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md)
