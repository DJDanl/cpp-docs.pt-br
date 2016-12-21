---
title: "Como migrar para /clr | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "get-started-article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /clr [C++], movimentando para"
  - "compilando código nativo [C++]"
  - "interoperabilidade [C++], Opção de compilador /clr"
  - "interoperabilidade [C++], Opção de compilador /clr"
  - "migração [C++], Opção de compilador /clr"
  - "atualizando aplicativos Visual C++, Opção de compilador /clr"
ms.assetid: c9290b8b-436a-4510-8b56-eae51f4a9afc
caps.latest.revision: 37
caps.handback.revision: 37
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como migrar para /clr
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico aborda problemas que ocorrem ao compilar o código nativo com **\/clr** \(consulte [\/clr \(compilação do Common Language Runtime\)](../build/reference/clr-common-language-runtime-compilation.md) para obter mais informações\).  **\/clr** permite que os módulos do Visual C\+\+ têm permissão para invocar e sejam invocados os assemblies do .NET para manter a compatibilidade com módulos não gerenciado.  Consulte [Assemblies mistos \(nativos e gerenciados\)](../Topic/Mixed%20\(Native%20and%20Managed\)%20Assemblies.md) e [Nativo e interoperabilidade .NET](../Topic/Native%20and%20.NET%20Interoperability.md) para obter mais informações sobre as vantagens de compilação com **\/clr**.  
  
## Problemas conhecidos que criam projetos de biblioteca com \/clr  
 Visual Studio contém alguns problemas conhecidos ao criar a biblioteca projetos com **\/clr**:  
  
-   O código pode tipos de consulta em tempo de execução com [CRuntimeClass::FromName](../Topic/CRuntimeClass::FromName.md).  No entanto, se um tipo está em um MSIL \(.dll compilado com **\/clr**\), a chamada para [CRuntimeClass::FromName](../Topic/CRuntimeClass::FromName.md) pode falhar se ocorrer antes da execução estático dos construtores no .dll gerenciado \(não verá esse problema se a chamada de FromName acontece depois que o código gerenciado executado no .dll\).  Para resolver esse problema, você pode forçar a construção do construtor estático gerenciado definindo uma função no .dll gerenciado, exportando e, ao invocar a do aplicativo MFC nativos.  Por exemplo:  
  
    ```  
    // Extension DLL Header file:  
    __declspec( dllexport ) void EnsureManagedInitialization () {  
       // managed code that won't be optimized away  
       System::GC::KeepAlive(System::Int32::MaxValue);  
    }  
    ```  
  
## Compile com o Visual C\+\+  
 Antes de usar **\/clr** em qualquer módulo em seu projeto, primeiro crie e vincular seu projeto nativo com o Visual Studio 2010.  
  
 As etapas a seguir, seguidas em ordem, forneça o caminho o mais fácil a uma compilação de **\/clr** .  É importante criar e executar o projeto depois de cada uma dessas etapas.  
  
### Versões anteriores do Visual C\+\+ 2003  
 Se você estiver atualizando do Visual Studio 2010 de uma versão anterior do Visual C\+\+ 2003, você pode ver os erros do compilador relacionados à conformidade padrão do C\+\+ aprimorado no Visual C\+\+ 2003  
  
### Atualização do Visual C\+\+ 2003  
 Prévio de projetos com Visual C\+\+ 2003 também deve primeiro ser compilado sem **\/clr** porque o Visual Studio tem gerado agora a conformidade de ANSI\/ISO e as algumas alterações.  É provável que a alteração exigir a maioria de atenção é [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  O código que usa o CRT muito provavelmente gerar avisos de substituição.  Esses avisos podem ser suprimidos, mas migrar a nova [Versões aprimoradas de segurança de funções CRT](../c-runtime-library/security-enhanced-versions-of-crt-functions.md) é preferencial, porque proporcionam melhor segurança e podem revelar problemas de segurança em seu código.  
  
### Atualização das extensões gerenciadas para C\+\+  
 Os projetos criados com o Visual C\+\+ .NET ou o Visual C\+\+ 2003 que usaram extensões gerenciadas para C\+\+ exigirão pelo menos uma alteração nas configurações de projeto, como essas extensões são substituídas agora.  No, o código escrito com extensões gerenciadas para C\+\+ não criará em **\/clr**.  Use **\/clr:oldSyntax** em vez disso.  
  
## Código C de converter em C\+\+  
 Embora o Visual Studio cria arquivos de 2.0 C, é necessário convertê\-los a C\+\+ para uma compilação de **\/clr** .  O nome de arquivo atual não tem que ser alterado; você pode usar **\/Tp** \(consulte\) [\/Tc, \/Tp, \/TC, \/TP \(especificar tipo de arquivo de origem\)](../build/reference/tc-tp-tc-tp-specify-source-file-type.md). Observe que embora os arquivos de código\-fonte C\+\+ sejam necessários para **\/clr**, não é necessário fator novamente seu código para usar paradigmas orientados a objeto.  
  
 Código C é muito provável exigir alterações quando criado porque arquivo c. criando  As regras de classificação segurança C\+\+ são restritas, de modo que as conversões de tipos devem ser feitas com conversões explícitas.  Por exemplo, o malloc retorna um ponteiro nulo, mas pode ser atribuído a um ponteiro para um determinado tipo em C com uma conversão:  
  
```  
int* a = malloc(sizeof(int));   // C code  
int* b = (int*)malloc(sizeof(int));   // C++ equivalent  
```  
  
 Os ponteiros de função também são estritamente tipo seguro em C\+\+, assim que o seguinte código C requer a alteração.  Em C\+\+ é melhor criar `typedef` que define o tipo de ponteiro de função, e depois usar esse tipo para converter ponteiros da função:  
  
```  
NewFunc1 = GetProcAddress( hLib, "Func1" );   // C code  
typedef int(*MYPROC)(int);   // C++ equivalent  
NewFunc2 = (MYPROC)GetProcAddress( hLib, "Func2" );  
```  
  
 C\+\+ também requer que as funções são definidas ou protótipos completo antes que possam ser referenciadas ou invocado.  
  
 Os identificadores usados em C código que acontecem ser palavras\-chave em C\+\+ \(como `virtual`, `new`, `delete`, `bool`, `true`, `false`, etc.\) devem ser renomeados.  Geralmente isso pode ser feito com simples de localização e substituição operações.  
  
 Finalmente, enquanto que as chamadas do COM o estilo 2.0 \- c requerem o uso explícito de v\- tabela e do ponteiro de `this` , C\+\+ não tem:  
  
```  
COMObj1->lpVtbl->Method(COMObj, args);  // C code  
COMObj2->Method(args);  // C++ equivalent  
```  
  
## Reconfigurar configurações de projeto  
 Após seu projeto do cria e executa no Visual Studio 2010 que você deve criar novas configurações de projeto para **\/clr** em vez de alterar as configurações padrão.  **\/clr** é incompatível com algumas opções do compilador e criar configurações separadas permite a você criar seu projeto como o modo nativo ou gerenciado.  Quando **\/clr** é selecionado nas páginas de propriedades caixa de diálogo, as configurações do projeto não compatíveis com **\/clr** são desabilitadas \(e as opções desabilitadas não são restauradas automaticamente se **\/clr** é cancelado a seleção subsequentemente\).  
  
### Crie novas configurações de projeto  
 Você pode usar a opção de **Copiar configurações de** em [New Project Configuration Dialog Box](http://msdn.microsoft.com/pt-br/cca616dc-05a6-4fe3-bdc1-40c72a66f2be) criar uma configuração de projeto com base nas configurações existentes do projeto.  Faça isto uma vez para a configuração de depuração e outra para a instalação da versão.  As alterações subsequentes podem ser aplicadas às configurações específico de **\/clr** , deixando apenas as configurações originais do projeto intactos.  
  
 Os projetos que usam regras personalizadas da construção podem exigir a atenção adicional.  
  
 Esta etapa tem implicações diferentes para projetos que usam makefiles.  Nesse caso construção\- um destino separado pode ser configurado, ou o específico da versão da compilação de **\/clr** pode ser criada de uma cópia original.  
  
### Configurações de projeto de alteração  
 **\/clr** pode ser selecionado no ambiente de desenvolvimento seguindo as instruções em [\/clr \(compilação do Common Language Runtime\)](../build/reference/clr-common-language-runtime-compilation.md).  Conforme mencionado anteriormente, essa etapa desabilitará automaticamente conflitantes configurações de projeto.  
  
> [!NOTE]
>  Ao atualizar um projeto gerenciado de biblioteca ou do serviço Web do Visual C\+\+ 2003, a opção de compilador de **\/Zl** adicionado a **Linha de Comando** a página de propriedades.  Isso fará LNK2001.  Remover **\/Zl** da página de propriedades de **Linha de Comando** a ser resolvido.  Consulte [\/Zl \(omitir nome da biblioteca padrão\)](../build/reference/zl-omit-default-library-name.md) e [Como abrir páginas de propriedade do projeto](../misc/how-to-open-project-property-pages.md) para obter mais informações.  Ou, adicione msvcrt.lib e msvcmrt.lib à propriedade de **Dependências Adicionais** do vinculador.  
  
 Para projetos desenvolvidos com makefiles, as opções do compilador incompatíveis devem ser desabilitadas manualmente uma vez que **\/clr** é adicionado.  Consulte\/[\/clr Restrições](../build/reference/clr-restrictions.md) para obter informações sobre as opções do compilador que não são compatíveis com **\/clr**.  
  
### Cabeçalhos pré\-compilados  
 Os cabeçalhos pré\-compilados têm suporte em **\/clr**.  No entanto, se você criar apenas alguns de seus arquivos de CPP com **\/clr** \(que cria o restante como o nativo\) algumas alterações serão necessárias como os cabeçalhos pré\-compilados gerados com **\/clr** não são compatíveis com os gerados sem **\/clr**.  Essa incompatibilidade ocorre devido ao fato de que **\/clr** gerencia e exige metadados.  **\/clr** compilado os módulos em virtude disso pode não os cabeçalhos pré\-compilados de uso que não contêm metadados, e não os módulos de **\/clr** não podem usar os arquivos de cabeçalho pré\-compilados que contêm a meta \- dados.  
  
 A maneira mais fácil de criar um projeto onde alguns módulos sejam **\/clr** compilado é desabilitar completamente cabeçalhos pré\-compilados. \(Na caixa de diálogo páginas de propriedades do projeto, abra o nó C\/C\+\+, selecione e cabeçalhos pré\-compilados.  Altere a propriedade pré\-compilada de cabeçalhos de criação\/use “que não usa cabeçalhos pré\-compilados”\).  
  
 No entanto, particularmente para grandes projetos, os cabeçalhos pré\-compilados fornecem muito melhor a velocidade da compilação, portanto desabilitar esse recurso não é desejável.  Nesse caso é melhor configurar **\/clr** e arquivos de **\/clr** não usar cabeçalhos pré\-compilados separados.  Isso pode ser feito em uma etapa várias selecionando os módulos para ser **\/clr** criado usando Solution Explorer, clique com o botão direito do mouse no grupo, e selecionando propriedades.  Altere o para criar\/uso PCH por meio de Arquivo e propriedades do Arquivo de cabeçalho pré\-compilados usar um nome de arquivo diferente do cabeçalho e o arquivo de PCH respectivamente.  
  
## Erros de composição  
 A compilação com **\/clr** pode resultar em erros do compilador, do vinculador ou de tempo de execução.  Esta seção discute os problemas mais comuns.  
  
### Mesclagem de metadados  
 As versões diferentes dos tipos de dados podem fazer com que o vinculador falhar porque os metadados gerados para os dois tipos de não corresponderem. \(Isso ocorre normalmente quando os membros de um tipo estejam definidos condicional, mas as condições não são as mesmas para todos os arquivos de CPP que usam o tipo.\) Nesse caso, o vinculador falha de relatório somente o nome de símbolo e o nome do segundo arquivo de OBJ onde o tipo foi definido.  Geralmente é útil ativar ou desativar a ordem em que os arquivos de OBJ serão enviados ao vinculador para descobrir o local da outra versão do tipo de dados.  
  
### Deadlock de bloqueios de carregador  
 No Visual C\+\+ .NET e Visual C\+\+ 2003, a inicialização em **\/clr** não existe deadlock não determinística.  Esse problema é conhecido como “o deadlock de bloqueio carregador”.  No Visual Studio 2010, esse deadlock é mais fácil de evitar, é detectado e relatado em tempo de execução, e não é mais não determinística.  Encontre o problema de bloqueio de carregador ainda é possível, mas agora é muito mais fácil evitar e corrigir.  Consulte para [Inicialização de assemblies mistos](../Topic/Initialization%20of%20Mixed%20Assemblies.md) plano de fundo, orientação, e soluções detalhados.  
  
### Exportações de dados  
 Exportar dados da DLL está sujeito a erros, e não recomendável.  Isso ocorre porque a seção de dados de uma DLL não é garantia de ser inicializada até que uma parte gerenciada da DLL seja executada.  Metadados de referência com [Diretiva \#using](../preprocessor/hash-using-directive-cpp.md).  
  
### Visibilidade do tipo  
 Os tipos nativos agora são privativos por padrão.  No Visual C\+\+ .NET 2002 e no Visual C\+\+ 2003, os tipos nativos foram públicos por padrão.  Isso pode resultar em um tipo nativo que não é visível fora da DLL.  Resolver este erro `public` adicionando a esses tipos.  Consulte [Visibilidade do tipo e do membro](../Topic/Type%20and%20Member%20Visibility.md) para maiores informações.  
  
### Problemas de ponto flutuante e alinhamento  
 `__controlfp` não tem suporte em Common Language Runtime \(consulte [\_control87, \_controlfp, \_\_control87\_2](../Topic/_control87,%20_controlfp,%20__control87_2.md) para obter mais informações\).  CLR também não respeitará [align](../cpp/align-cpp.md).  
  
### Inicialização da  
 Common Language Runtime inicializa COM automaticamente quando um módulo é inicializada \(quando COM ele é iniciado automaticamente fez de modo a MTA\).  No resultado, explicitamente inicializar COM gerencie os códigos de retorno que indica que a já está inicializado.  Tentar inicializar COM explicitamente com um modelo de threading CLR quando já inicializou COM a outro modelo de threading pode causar o aplicativo falhar.  
  
 Inicia COM de Common Language Runtime como a MTA por padrão; use [\/CLRTHREADATTRIBUTE \(definir atributo de thread CLR\)](../build/reference/clrthreadattribute-set-clr-thread-attribute.md) para alterar isso.  
  
### Problemas de desempenho  
 Você pode ver desempenho reduzido quando os métodos C\+\+ nativos gerados a MSIL são chamados indiretamente \(chamadas de função virtuais ou o uso de ponteiros de função\).  Para saber mais sobre isso, consulte [Conversão dupla](../Topic/Double%20Thunking%20\(C++\).md).  
  
 Ao mover da MSIL nativo, você observará um aumento no tamanho do conjunto de trabalho.  Isso é porque Common Language Runtime fornece muitos recursos para garantir que os programas executados corretamente.  Se seu aplicativo de **\/clr** não está sendo executado corretamente, você pode habilitar C4793 \(desativado por padrão\), consulta [Aviso do compilador \(nível 1 e 3\) C4793](../error-messages/compiler-warnings/compiler-warning-level-1-and-3-c4793.md) para obter mais informações.  
  
### O programa falha no desligamento  
 Em alguns casos, CLR pode desconectar antes de executar o código gerenciado está concluído.  Usar `std::set_terminate` e `SIGTERM` pode causar isso.  Consulte [Constantes de sinal](../c-runtime-library/signal-constants.md) e [set\_terminate](../Topic/set_terminate%20\(%3Cexception%3E\).md) para obter mais informações.  
  
## Usando novos recursos do Visual C\+\+  
 Depois que seu aplicativo compila, vincula, e é executado, você pode começar a usar os recursos do .NET em qualquer módulo compilado com **\/clr**.  Para obter mais informações, consulte [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md).  
  
 Se você usou extensões gerenciadas para C\+\+, você pode converter seu código para usar a nova sintaxe.  Para obter um resumo das diferenças sintáticas, consulte [\(NOTINBUILD\)Managed Extensions for C\+\+ Syntax Upgrade Checklist](http://msdn.microsoft.com/pt-br/edbded88-7ef3-4757-bd9d-b8f48ac2aada).  Para obter detalhes da conversão de extensões gerenciadas para C\+\+, consulte [Primer de migração C\+\+\/CLI](../dotnet/cpp-cli-migration-primer.md).  
  
 Para obter informações sobre a programação do .NET no Visual C\+\+ consulte:  
  
-   [Programação do .NET com o C \+ \+ \/ CLI \(Visual C\+\+\)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)  
  
-   [Nativo e interoperabilidade .NET](../Topic/Native%20and%20.NET%20Interoperability.md)  
  
-   [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)  
  
## Consulte também  
 [Assemblies mistos \(nativos e gerenciados\)](../Topic/Mixed%20\(Native%20and%20Managed\)%20Assemblies.md)