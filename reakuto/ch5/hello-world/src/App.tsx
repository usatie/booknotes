import { FC } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'
import Greet from './components/Greet'
import Summary from './components/Summary'
import TextInput from './components/TextInput'

const name = "Patty";
const greet = (name: string) => <p>Hello, {name || "Guest"}!</p>;

const n = Math.floor(Math.random() * 10);
const threshold = 5;

const list = ['Patty', 'Rolley', 'Bobby'];

const App: FC = () => {
  return (
  	<>
		<div className="App">
			<header className="App-header">
				<img src={viteLogo} className="Vite-logo" alt="logo" />
				<img src={reactLogo} className="React-logo" alt="logo" />
				<p>Hello World!</p>
			</header>
		</div>
		{ /* This is a comment */ }
		{ /* Function call */ }
		<div>{greet(name)}</div>
		{ /* Ternary operator */ }
		<div>{ true ? "hello" : "world" }</div>
		<div>{ false ? "hello" : "world" }</div>
		{ /* Values not displayed */ }
		<div>{ null }</div>
		<div>{ undefined }</div>
		<div>{ true }</div>
		<div>{ false }</div>
		<div>{ '' }</div>
		{ /* 0 is displayed */ }
		<div>{ 0 }</div>
		{ /* Sometimes displayed */ }
		{ n > threshold && (<p>{ n } is greater than { threshold }</p>) }
		{ n > threshold || (<p>{ n } is less than or equal to { threshold }</p>) }
		{ /* Ternary operator */ }
		<p> {n} is { n % 2 === 0 ? "even" : "odd" }</p>
		{ /* Loop */ }
		{/*
		<ul>
			{ list.map((name, i) => <li>Hello, { name }!</li>) }
		</ul>
		*/}
		{ /* Comment */ }
		{
			// inline comment
		}
		{ /* Multi-line comment */ }
		{ /* 5-2-2. Component */ }
		<Greet name="Patty" times={4} />
		<Summary title="Maple Town" folded>
			<p>
				Patty Hope-rabbit, along with her family, arrives in Maple Town, a smalltown inhabited by friendly animals.
			</p>
			<p>
				Soon, the Rabbit Family settles in Maple Town as mail carriers and the bitter, yet sweet friendship of Patty and Bobby begins to blossom.
			</p>	
		</Summary>
		{/* <select> and <textarea> */}
		<form>
			<label htmlFor="favChar">Who is your favorite character?</label>
			{ /* <select id="favChar" value="fox"> */ }
			<select id = "favChar" defaultValue="fox">
				<option value="rabbit">Patty</option>
				<option value="bear">Bobby</option>
				<option value="fox">Diana</option>
				<option value="pig">PuddiPudding</option>
			</select>
		</form>
		<TextInput />
	</>
  );
};

export default App
