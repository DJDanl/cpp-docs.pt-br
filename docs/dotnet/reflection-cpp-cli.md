---
title: Reflexão (C++/CLI)
ms.date: 11/04/2016
helpviewer_keywords:
- typeid keyword [C++]
- reflection [C++}, about reflection
- metadata, reflection
- GetType method
- .NET Framework [C++], reflection
- data types [C++], reflection
- reflection [C++}
- plug-ins [C++]
- reflection [C++}, plug-ins
- assemblies [C++], enumerating data types in
- public types [C++]
- reflection [C++], external assemblies
- assemblies [C++]
- data types [C++], enumerating
- public members [C++]
ms.assetid: 46b6ff4a-e441-4022-8892-78e69422f230
ms.openlocfilehash: 769ba87f64a8096ac8c7f14cc091119345177b3b
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57426440"
---
# <a name="reflection-ccli"></a>Reflexão (C++/CLI)

Reflexão permite que os tipos de dados conhecidos ser inspecionado em tempo de execução. Reflexão permite que a enumeração dos tipos de dados em um determinado assembly, e os membros de um determinado tipo de classe ou o valor podem ser descobertos. Isso é verdadeiro independentemente do tipo foi conhecido ou referenciado em tempo de compilação. Isso torna a reflexão um recurso útil para desenvolvimento e as ferramentas de gerenciamento de código.

Observe que o nome do assembly fornecido é o nome forte (consulte [criando e usando Assemblies nomes fortes](/dotnet/framework/app-domains/create-and-use-strong-named-assemblies)), que inclui a versão do assembly, cultura e informações de assinatura. Observe também que o nome do namespace no qual o tipo de dados é definido pode ser recuperado, junto com o nome da classe base.

A maneira mais comum para acessar recursos de reflexão é por meio de <xref:System.Object.GetType%2A> método. Este método é fornecido por <xref:System.Object?displayProperty=nameWithType>, da qual derivam todas as classes de coleta de lixo.

> [!NOTE]
> Reflexão em um .exe criados com o compilador do Visual C++ só será permitido se o .exe baseia-se com o **/clr: pure** ou **/CLR: safe** opções do compilador. O **/clr: pure** e **/CLR: safe** opções do compilador são preteridos no Visual Studio 2015 e não está disponível no Visual Studio 2017. Ver [/clr (compilação de tempo de execução de linguagem comum)](../build/reference/clr-common-language-runtime-compilation.md) para obter mais informações.

Para obter mais informações, consulte <xref:System.Reflection>.

## <a name="example-gettype"></a>Exemplo: GetType

O `GetType` método retorna um ponteiro para um <xref:System.Type> objeto de classe, que descreve o tipo após quando o objeto é baseado. (O **tipo** objeto não contém quaisquer informações específicas da instância.) Um desses itens é o nome completo do tipo, que pode ser exibido da seguinte maneira:

Observe que o nome do tipo inclui o escopo completo no qual o tipo é definido, incluindo o namespace, e que ele é exibido na sintaxe do .NET, com um ponto como o operador de resolução de escopo.

```cpp
// vcpp_reflection.cpp
// compile with: /clr
using namespace System;
int main() {
   String ^ s = "sample string";
   Console::WriteLine("full type name of '{0}' is '{1}'", s, s->GetType());
}
```

```Output
full type name of 'sample string' is 'System.String'
```

## <a name="example-boxed-value-types"></a>Exemplo: tipos de valor demarcado

Tipos de valor podem ser usados com o `GetType` funcionar bem, mas deve ser boxed pela primeira vez.

```cpp
// vcpp_reflection_2.cpp
// compile with: /clr
using namespace System;
int main() {
   Int32 i = 100;
   Object ^ o = i;
   Console::WriteLine("type of i = '{0}'", o->GetType());
}
```

```Output
type of i = 'System.Int32'
```

## <a name="example-typeid"></a>Exemplo: typeid

Assim como acontece com o `GetType` método, o [typeid](../windows/typeid-cpp-component-extensions.md) operador retorna um ponteiro para um **tipo** do objeto, portanto, esse código indica o nome do tipo **System.Int32**. Exibindo nomes de tipo é o recurso mais básico de reflexão, mas uma técnica potencialmente mais úteis é inspecionar ou descobrir os valores válidos para os tipos enumerados. Isso pode ser feito usando a estatística **Enum::GetNames** de função, que retorna uma matriz de cadeias de caracteres, cada um contendo um valor de enumeração na forma de texto.  O exemplo a seguir recupera uma matriz de cadeias de caracteres que descreve os valores de enumeração de valor para o **opções** enum (CLR) e os exibe em um loop.

Se uma quarta opção é adicionada a **opções** enumeração, esse código relatará a nova opção sem recompilação, mesmo se a enumeração for definida em um assembly separado.

```cpp
// vcpp_reflection_3.cpp
// compile with: /clr
using namespace System;

enum class Options {   // not a native enum
   Option1, Option2, Option3
};

int main() {
   array<String^>^ names = Enum::GetNames(Options::typeid);

   Console::WriteLine("there are {0} options in enum '{1}'",
               names->Length, Options::typeid);

   for (int i = 0 ; i < names->Length ; i++)
      Console::WriteLine("{0}: {1}", i, names[i]);

   Options o = Options::Option2;
   Console::WriteLine("value of 'o' is {0}", o);
}
```

```Output
there are 3 options in enum 'Options'
0: Option1
1: Option2
2: Option3
value of 'o' is Option2
```

## <a name="example-gettype-members-and-properties"></a>Exemplo: Propriedades e membros de GetType

O `GetType` objeto dá suporte a um número de membros e propriedades que podem ser usadas para examinar um tipo. Esse código recupera e exibe algumas dessas informações:

```cpp
// vcpp_reflection_4.cpp
// compile with: /clr
using namespace System;
int main() {
   Console::WriteLine("type information for 'String':");
   Type ^ t = String::typeid;

   String ^ assemblyName = t->Assembly->FullName;
   Console::WriteLine("assembly name: {0}", assemblyName);

   String ^ nameSpace = t->Namespace;
   Console::WriteLine("namespace: {0}", nameSpace);

   String ^ baseType = t->BaseType->FullName;
   Console::WriteLine("base type: {0}", baseType);

   bool isArray = t->IsArray;
   Console::WriteLine("is array: {0}", isArray);

   bool isClass = t->IsClass;
   Console::WriteLine("is class: {0}", isClass);
}
```

```Output
type information for 'String':
assembly name: mscorlib, Version=1.0.5000.0, Culture=neutral,
PublicKeyToken=b77a5c561934e089
namespace: System
base type: System.Object
is array: False
is class: True
```

## <a name="example-enumeration-of-types"></a>Exemplo: enumeração dos tipos

Reflexão também permite que a enumeração dos tipos em um assembly e os membros dentro de classes. Para demonstrar esse recurso, defina uma classe simple:

```cpp
// vcpp_reflection_5.cpp
// compile with: /clr /LD
using namespace System;
public ref class TestClass {
   int m_i;
public:
   TestClass() {}
   void SimpleTestMember1() {}
   String ^ SimpleMember2(String ^ s) { return s; }
   int TestMember(int i) { return i; }
   property int Member {
      int get() { return m_i; }
      void set(int i) { m_i = i; }
   }
};
```

## <a name="example-inspection-of-assemblies"></a>Exemplo: inspeção de assemblies

Se o código acima é compilado em uma DLL chamada vcpp_reflection_6.dll, você pode usar reflexão para inspecionar o conteúdo desse assembly. Isso envolve o uso de reflexão estática API função xref:System.Reflection.Assembly.Load%2A?displayProperty=nameWithType para carregar o assembly. Essa função retorna o endereço de um **Assembly** objeto que pode ser consultado, em seguida, sobre os módulos e tipos.

Depois que o sistema de reflexão com êxito carrega o assembly, uma matriz de **tipo** objetos é recuperada com o <xref:System.Reflection.Assembly.GetTypes%2A?displayProperty=nameWithType> função. Cada elemento da matriz contém informações sobre um tipo diferente, embora nesse caso, apenas uma classe é definida. Usando um loop, cada **tipo** nessa matriz é consultado sobre os membros de tipo usando o **Type::GetMembers** função. Essa função retorna uma matriz de **MethodInfo** objetos, cada objeto que contém informações sobre a função de membro, um membro de dados ou uma propriedade no tipo.

Observe que a lista de métodos inclui as funções explicitamente definidas em **TestClass** e as funções herdados implicitamente do **System:: Object** classe. Como parte do que está sendo descrito no .NET, em vez de na sintaxe do Visual C++, as propriedades aparecem como o membro de dados subjacente, acessado pelas funções de get/set. As funções get/set aparecem nessa lista como métodos regulares. Reflexão suporte por meio do common language runtime, não o compilador do Visual C++.

Embora você utilizou este código para inspecionar um assembly que você definiu, você também pode usar esse código para inspecionar os assemblies do .NET. Por exemplo, se você alterar TestAssembly para mscorlib, você verá uma lista de todos os tipos e método definido em mscorlib. dll.

```cpp
// vcpp_reflection_6.cpp
// compile with: /clr
using namespace System;
using namespace System::IO;
using namespace System::Reflection;
int main() {
   Assembly ^ a = nullptr;
   try {
      // load assembly -- do not use file extension
      // will look for .dll extension first
      // then .exe with the filename
      a = Assembly::Load("vcpp_reflection_5");
   }
   catch (FileNotFoundException ^ e) {
      Console::WriteLine(e->Message);
      return -1;
   }

   Console::WriteLine("assembly info:");
   Console::WriteLine(a->FullName);
   array<Type^>^ typeArray = a->GetTypes();

   Console::WriteLine("type info ({0} types):", typeArray->Length);

   int totalTypes = 0;
   int totalMembers = 0;
   for (int i = 0 ; i < typeArray->Length ; i++) {
      // retrieve array of member descriptions
      array<MemberInfo^>^ member = typeArray[i]->GetMembers();

      Console::WriteLine("  members of {0} ({1} members):",
      typeArray[i]->FullName, member->Length);
      for (int j = 0 ; j < member->Length ; j++) {
         Console::Write("       ({0})",
         member[j]->MemberType.ToString() );
         Console::Write("{0}  ", member[j]);
         Console::WriteLine("");
         totalMembers++;
      }
      totalTypes++;
   }
   Console::WriteLine("{0} total types, {1} total members",
   totalTypes, totalMembers);
}
```

## <a name="implement"></a> Como: Implementar uma arquitetura de componente de plug-in usando a reflexão

Os exemplos de código a seguir demonstram o uso da reflexão para implementar uma arquitetura de "plug-in" simples. A primeira listagem é o aplicativo e o segundo é o plug-in. O aplicativo é um formulário de vários documentos que popula a mesmo usando qualquer baseado em formulário das classes encontradas na DLL plug-in fornecido como um argumento de linha de comando.

O aplicativo tenta carregar o assembly fornecido usando o <xref:System.Reflection.Assembly.Load%2A?displayProperty=fullName> método. Se for bem-sucedido, os tipos dentro do assembly são enumerados usando a <xref:System.Reflection.Assembly.GetTypes%2A?displayProperty=fullName> método. Cada tipo é então verificado para compatibilidade usando o <xref:System.Type.IsAssignableFrom%2A?displayProperty=fullName> método. Neste exemplo, classes encontradas no assembly fornecido devem ser derivadas de <xref:System.Windows.Forms.Form> classe para ser qualificado como um plug-in.

Compatível com classes, em seguida, são instanciadas com o <xref:System.Activator.CreateInstance%2A?displayProperty=fullName> método, que aceita um <xref:System.Type> como um argumento e retorna um ponteiro para uma nova instância. Cada nova instância, em seguida, é anexada ao formulário e exibida.

Observe que o <xref:System.Reflection.Assembly.Load%2A> método não aceita nomes de assembly que incluem a extensão de arquivo. A função principal no aplicativo corta quaisquer extensões fornecidos, portanto, o exemplo de código a seguir funciona em ambos os casos.

### <a name="example"></a>Exemplo

O código a seguir define o aplicativo que aceita o plug-ins. Um nome de assembly deve ser fornecido como o primeiro argumento. Esse assembly deve conter pelo menos um público <xref:System.Windows.Forms.Form> tipo derivado.

```cpp
// plugin_application.cpp
// compile with: /clr /c
#using <system.dll>
#using <system.drawing.dll>
#using <system.windows.forms.dll>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Reflection;

ref class PluggableForm : public Form  {
public:
   PluggableForm() {}
   PluggableForm(Assembly^ plugAssembly) {
      Text = "plug-in example";
      Size = Drawing::Size(400, 400);
      IsMdiContainer = true;

      array<Type^>^ types = plugAssembly->GetTypes( );
      Type^ formType = Form::typeid;

      for (int i = 0 ; i < types->Length ; i++) {
         if (formType->IsAssignableFrom(types[i])) {
            // Create an instance given the type description.
            Form^ f = dynamic_cast<Form^> (Activator::CreateInstance(types[i]));
            if (f) {
               f->Text = types[i]->ToString();
               f->MdiParent = this;
               f->Show();
            }
         }
      }
   }
};

int main() {
   Assembly^ a = Assembly::LoadFrom("plugin_application.exe");
   Application::Run(gcnew PluggableForm(a));
}
```

### <a name="example"></a>Exemplo

O código a seguir define três classes derivadas de <xref:System.Windows.Forms.Form>. Quando o nome do nome do assembly resultante é passado para o executável na lista anterior, cada uma dessas três classes será descoberta e instanciada, apesar do fato de que eles foram todos desconhecidos para o aplicativo de hospedagem em tempo de compilação.

```cpp
// plugin_assembly.cpp
// compile with: /clr /LD
#using <system.dll>
#using <system.drawing.dll>
#using <system.windows.forms.dll>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Reflection;
using namespace System::Drawing;

public ref class BlueForm : public Form {
public:
   BlueForm() {
      BackColor = Color::Blue;
   }
};

public ref class CircleForm : public Form {
protected:
   virtual void OnPaint(PaintEventArgs^ args) override {
      args->Graphics->FillEllipse(Brushes::Green, ClientRectangle);
   }
};

public ref class StarburstForm : public Form {
public:
   StarburstForm(){
      BackColor = Color::Black;
   }
protected:
   virtual void OnPaint(PaintEventArgs^ args) override {
      Pen^ p = gcnew Pen(Color::Red, 2);
      Random^ r = gcnew Random( );
      Int32 w = ClientSize.Width;
      Int32 h = ClientSize.Height;
      for (int i=0; i<100; i++) {
         float x1 = w / 2;
         float y1 = h / 2;
         float x2 = r->Next(w);
         float y2 = r->Next(h);
         args->Graphics->DrawLine(p, x1, y1, x2, y2);
      }
   }
};
```

## <a name="enumerate"></a> Como: Enumerar tipos de dados em Assemblies usando reflexão

O código a seguir demonstra a enumeração dos tipos públicos e membros usando <xref:System.Reflection>.

Considerando o nome de um assembly no diretório local ou no GAC, o código a seguir tenta abrir o assembly e recuperar as descrições. Se for bem-sucedido, cada tipo é exibido com seus membros públicos.

Observe que <xref:System.Reflection.Assembly.Load%2A?displayProperty=fullName> requer que nenhuma extensão de arquivo é usado. Portanto, usar "mscorlib. dll" como um argumento de linha de comando falhará, enquanto usar apenas "mscorlib", resultará a exibição de tipos do .NET Framework. Se nenhum nome de assembly for fornecido, o código será detectam e relatam os tipos no assembly atual (o EXE resultantes desse código).

### <a name="example"></a>Exemplo

```cpp
// self_reflection.cpp
// compile with: /clr
using namespace System;
using namespace System::Reflection;
using namespace System::Collections;

public ref class ExampleType {
public:
   ExampleType() {}
   void Func() {}
};

int main() {
   String^ delimStr = " ";
   array<Char>^ delimiter = delimStr->ToCharArray( );
   array<String^>^ args = Environment::CommandLine->Split( delimiter );

// replace "self_reflection.exe" with an assembly from either the local
// directory or the GAC
   Assembly^ a = Assembly::LoadFrom("self_reflection.exe");
   Console::WriteLine(a);

   int count = 0;
   array<Type^>^ types = a->GetTypes();
   IEnumerator^ typeIter = types->GetEnumerator();

   while ( typeIter->MoveNext() ) {
      Type^ t = dynamic_cast<Type^>(typeIter->Current);
      Console::WriteLine("   {0}", t->ToString());

      array<MemberInfo^>^ members = t->GetMembers();
      IEnumerator^ memberIter = members->GetEnumerator();
      while ( memberIter->MoveNext() ) {
         MemberInfo^ mi = dynamic_cast<MemberInfo^>(memberIter->Current);
         Console::Write("      {0}", mi->ToString( ) );
         if (mi->MemberType == MemberTypes::Constructor)
            Console::Write("   (constructor)");

         Console::WriteLine();
      }
      count++;
   }
   Console::WriteLine("{0} types found", count);
}
```

## <a name="see-also"></a>Consulte também

- [Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)
